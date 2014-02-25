
void  setup_imu() {

  Wire.begin();
  dueMPU.useAccelCal(false);
  dueMPU.useMagCal(false);
  dueMPU.selectDevice(DEVICE_TO_USE);                        // only really necessary if using device 1
  imu_fault=!dueMPU.init(MPU_UPDATE_RATE, MPU_MAG_MIX_GYRO_AND_MAG, MAG_UPDATE_RATE, MPU_LPF_RATE);   // start the MPU
CHECK_IMU_INTERVAL=(unsigned long)(1000.0/MPU_UPDATE_RATE*50.0);
}



void read_imu() {
  if (dueMPU.read()) {       // get the latest data if ready yet
    qw = dueMPU.m_fusedQuaternion[0];
    qx = dueMPU.m_fusedQuaternion[1];
    qy = dueMPU.m_fusedQuaternion[2];
    qz = dueMPU.m_fusedQuaternion[3];
    imu_t=millis();
  }

}

