
void  setup_imu() {
  
  Wire.begin();
   dueMPU.useAccelCal(false);
 dueMPU.useMagCal(false);
  dueMPU.selectDevice(DEVICE_TO_USE);                        // only really necessary if using device 1
  dueMPU.init(MPU_UPDATE_RATE, MPU_MAG_MIX_GYRO_AND_MAG, MAG_UPDATE_RATE, MPU_LPF_RATE);   // start the MPU
}



void read_imu() {
  if (dueMPU.read()) {       // get the latest data if ready yet
 
    qw = dueMPU.m_fusedQuaternion[0];
    qx = dueMPU.m_fusedQuaternion[1];
   qy = dueMPU.m_fusedQuaternion[2];
    qz = dueMPU.m_fusedQuaternion[3];

  }
}

