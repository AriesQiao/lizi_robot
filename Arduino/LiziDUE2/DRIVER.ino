
void setup_driver() {

  Setpoint1 = 0;
  Setpoint2 = 0;
  PID1.SetSampleTime(CONTROL_INTERVAL);
  PID2.SetSampleTime(CONTROL_INTERVAL);
  DT = (double)READ_ENCODERS_INTERVAL / 1000.0;
  PID1.SetMode(AUTOMATIC);
  PID2.SetMode(AUTOMATIC);
  PID1.SetOutputLimits(-255, 255);
  PID2.SetOutputLimits(-255, 255);
  md.init();
  md.restart();


  stop_motors();


}



void read_status() {

  int faults_bit = md.getFault();
  int torque_bit = !md.getTorque();
  int gps_fix_bit = !gps.location.isValid();
int imu_bit=(int)imu_fault;
  status_msg.faults = 8*imu_bit + 4 * gps_fix_bit + 2 * torque_bit + faults_bit;
  status_msg.battery_voltage = (float)analogRead(BATTERY_MONITOR_PIN) * 3.3 / 4096 * VOLTAGE_DIVIDER_RATIO;
  p_status.publish(&status_msg);

}


void  read_encoders() {
  pre_left_enc = left_enc;
  pre_right_enc = right_enc;

  left_enc = Enc2.read(); //left
  right_enc = Enc1.read(); //right

  left_spd = alpha * (double)(left_enc - pre_left_enc) / DT  + (1 - alpha) * (double)left_spd;
  right_spd = alpha * (double)(right_enc - pre_right_enc) / DT + (1 - alpha) * (double)right_spd;

  Input2 = left_spd;
  Input1 = right_spd;
}

void control_loop() {


  if ( (PID1.Compute()) && (PID2.Compute()) ) {
    md.setSpeeds((int)Output1, (int)Output2);
    // nh.loginfo("a");
  }

}






void set_parametersCb(const set_parameters::Request & req, set_parameters::Response & res) {

  /*
  if ((req.kp == 0) && (req.ki == 0)&&(req.kd == 0)&&(req.alpha == 0)) {
  nh.loginfo("Setting lizi ID (will only take effect after next reboot)");
    id[0]=req.control_dt;
  flash1.write(FLASH_START, id, DATA_LENGTH);

  char log_msg[30];
    sprintf(log_msg, "New id is: = %d", (int)(((uint32_t *)FLASH_START)[0]) );
    nh.loginfo(log_msg);

  }

  else {*/
  PID1.SetTunings(req.kp, req.ki, req.kd);
  PID2.SetTunings(req.kp, req.ki, req.kd);
  alpha = req.alpha;
  CONTROL_INTERVAL = req.control_dt;
  PID1.SetSampleTime(CONTROL_INTERVAL);
  PID2.SetSampleTime(CONTROL_INTERVAL);
  //DT=(double)CONTROL_INTERVAL/1000.0;
  char log_msg[30];

  nh.loginfo("Setting parameters");
  sprintf(log_msg, "kp*10000 = %d", (int)(kp * 10000));
  nh.loginfo(log_msg);


  sprintf(log_msg, "ki*10000 = %d", (int)(ki * 10000));
  nh.loginfo(log_msg);


  sprintf(log_msg, "kd*10000 = %d", (int)(kd * 10000));
  nh.loginfo(log_msg);


  sprintf(log_msg, "alpha*10000 = %d", (int)(alpha * 10000));
  nh.loginfo(log_msg);

  sprintf(log_msg, "Control loop dt = %d", CONTROL_INTERVAL);
  nh.loginfo(log_msg);

  // }
}

void reset_encCb(const Empty::Request & req, Empty::Response & res) {
  Enc1.write(0);
  Enc2.write(0);

  left_enc = 0;
  right_enc = 0;
  left_spd = 0;
  right_spd = 0;
  nh.loginfo("Reset encoders");

}

void commandCb( const lizi::lizi_command& msg) {
  if (wd_on) {
    wd_on = false;
    md.setTorque(true);
  }
  wd_t = millis();

  Setpoint2 = -msg.left_wheel;
  Setpoint1 = msg.right_wheel;
  if (Setpoint1 > MAX_TICKS_PER_S) Setpoint1 = MAX_TICKS_PER_S;
  else if (Setpoint1 < -MAX_TICKS_PER_S) Setpoint1 = -MAX_TICKS_PER_S;
  if (Setpoint2 > MAX_TICKS_PER_S) Setpoint2 = MAX_TICKS_PER_S;
  else if (Setpoint2 < -MAX_TICKS_PER_S) Setpoint2 = -MAX_TICKS_PER_S;

}

void stop_motors( ) {


  Setpoint1 = 0;
  Setpoint2 = 0;
  md.setSpeeds(0, 0); //+-255
  md.setTorque(false);
}


