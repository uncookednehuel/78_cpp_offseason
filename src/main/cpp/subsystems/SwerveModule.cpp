// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SwerveModule.h"
#include <rev/CANSparkMax.h> // Include the necessary header file

SwerveModule::SwerveModule(int driveID, int steerID, ModuleConfig &config, FFConstants &ffConstants) 
        : driveMotor(driveID, rev::CANSparkMax::MotorType::kBrushless),
            steerMotor(steerID, rev::CANSparkMax::MotorType::kBrushless) {
        SwerveModule::config = config; // Set the config field to the passed config
        SwerveModule::ffConstants = ffConstants; // Set the ffConstants field to the passed ffConstants
}

void SwerveModule::init() {
    driveMotor.RestoreFactoryDefaults(); // Use driveMotor without '->'
    steerMotor.RestoreFactoryDefaults(); // Use steerMotor without '->'
}

frc::SwerveModuleState SwerveModule::getRealState() {
    return frc::SwerveModuleState(); // Return a SwerveModuleState object
}