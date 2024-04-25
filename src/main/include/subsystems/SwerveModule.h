// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/kinematics/SwerveModuleState.h>
#include <rev/CANSparkMax.h>

class SwerveModule
{
public:
  struct FFConstants
  {
    double ks;
    double kv;
    double ka;
  };

  struct ModuleConfig
  {
    double driveGearRatio;
    double steerGearRatio;
    bool driveMotorReversed;
    bool steerMotorReversed;
    bool steerEncoderReversed;
  };

  rev::CANSparkMax driveMotor;
  rev::CANSparkMax steerMotor;
  ModuleConfig config;
  FFConstants ffConstants;

  SwerveModule(int driveID, int steerID, ModuleConfig &config, FFConstants &ffConstants);

  void init();
  void setDesiredState(double speed, double angle);
  frc::SwerveModuleState getRealState();
  frc::SwerveModuleState getOptimizedState();
};
