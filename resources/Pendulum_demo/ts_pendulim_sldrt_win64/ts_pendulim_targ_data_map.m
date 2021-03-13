  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ts_pendulim_P)
    ;%
      section.nData     = 71;
      section.data(71)  = dumData; %prealloc
      
	  ;% ts_pendulim_P.RefCartPos_Amplitude
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ts_pendulim_P.PIDController_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ts_pendulim_P.RefCartPos_Frequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ts_pendulim_P.PIDController_I
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ts_pendulim_P.PIDController_N
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ts_pendulim_P.RefCartPos_Sawtooth
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ts_pendulim_P.RefCartPos_Sine
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ts_pendulim_P.RefCartPos_Square
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ts_pendulim_P.Sensors_T0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ts_pendulim_P.AlfaNormalization_pos
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ts_pendulim_P.Normal_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ts_pendulim_P.Reset_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ts_pendulim_P.pi_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ts_pendulim_P.Encoder_P1_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ts_pendulim_P.Encoder_P1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 15;
	
	  ;% ts_pendulim_P.Encoder_P2_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 16;
	
	  ;% ts_pendulim_P.Encoder_P2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% ts_pendulim_P.Encoder1024PPR_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% ts_pendulim_P.AngleScale_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% ts_pendulim_P.Gain1_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 21;
	
	  ;% ts_pendulim_P.Memory_X0
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 22;
	
	  ;% ts_pendulim_P.PosCartScale_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 23;
	
	  ;% ts_pendulim_P.CartOffset_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 24;
	
	  ;% ts_pendulim_P.Gain3_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 25;
	
	  ;% ts_pendulim_P.Memory1_X0
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 26;
	
	  ;% ts_pendulim_P.Gain_Gain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 27;
	
	  ;% ts_pendulim_P.Memory_X0_o
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 28;
	
	  ;% ts_pendulim_P.Gain1_Gain_f
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 29;
	
	  ;% ts_pendulim_P.PWM_P1_Size
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 30;
	
	  ;% ts_pendulim_P.PWM_P1
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 32;
	
	  ;% ts_pendulim_P.PWM_P2_Size
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% ts_pendulim_P.PWM_P2
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 35;
	
	  ;% ts_pendulim_P.Normal1_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 36;
	
	  ;% ts_pendulim_P.Saturation_UpperSat
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 37;
	
	  ;% ts_pendulim_P.Saturation_LowerSat
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 38;
	
	  ;% ts_pendulim_P.ResetEncoder_P1_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 39;
	
	  ;% ts_pendulim_P.ResetEncoder_P1
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 41;
	
	  ;% ts_pendulim_P.ResetEncoder_P2_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 42;
	
	  ;% ts_pendulim_P.ResetEncoder_P2
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 44;
	
	  ;% ts_pendulim_P.ResetSource_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 45;
	
	  ;% ts_pendulim_P.LimitFlag_P1_Size
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 48;
	
	  ;% ts_pendulim_P.LimitFlag_P1
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 50;
	
	  ;% ts_pendulim_P.LimitFlag_P2_Size
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 51;
	
	  ;% ts_pendulim_P.LimitFlag_P2
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 53;
	
	  ;% ts_pendulim_P.LimitFlagSource_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 54;
	
	  ;% ts_pendulim_P.LimitSource_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 57;
	
	  ;% ts_pendulim_P.SetLimit_P1_Size
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 60;
	
	  ;% ts_pendulim_P.SetLimit_P1
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 62;
	
	  ;% ts_pendulim_P.SetLimit_P2_Size
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 63;
	
	  ;% ts_pendulim_P.SetLimit_P2
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 65;
	
	  ;% ts_pendulim_P.LimitSwitch_P1_Size
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 66;
	
	  ;% ts_pendulim_P.LimitSwitch_P1
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 68;
	
	  ;% ts_pendulim_P.LimitSwitch_P2_Size
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 69;
	
	  ;% ts_pendulim_P.LimitSwitch_P2
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 71;
	
	  ;% ts_pendulim_P.PWMPrescaler_P1_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 72;
	
	  ;% ts_pendulim_P.PWMPrescaler_P1
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 74;
	
	  ;% ts_pendulim_P.PWMPrescaler_P2_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 75;
	
	  ;% ts_pendulim_P.PWMPrescaler_P2
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 77;
	
	  ;% ts_pendulim_P.PWMPrescalerSource_Value
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 78;
	
	  ;% ts_pendulim_P.ResetSwitchFlag_P1_Size
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 79;
	
	  ;% ts_pendulim_P.ResetSwitchFlag_P1
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 81;
	
	  ;% ts_pendulim_P.ResetSwitchFlag_P2_Size
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 82;
	
	  ;% ts_pendulim_P.ResetSwitchFlag_P2
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 84;
	
	  ;% ts_pendulim_P.ResetSwitchFlagSource_Value
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 85;
	
	  ;% ts_pendulim_P.ThermFlag_P1_Size
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 88;
	
	  ;% ts_pendulim_P.ThermFlag_P1
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 90;
	
	  ;% ts_pendulim_P.ThermFlag_P2_Size
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 91;
	
	  ;% ts_pendulim_P.ThermFlag_P2
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 93;
	
	  ;% ts_pendulim_P.ThermFlagSource_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 94;
	
	  ;% ts_pendulim_P.Filter_IC
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 97;
	
	  ;% ts_pendulim_P.Integrator_IC
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 98;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ts_pendulim_P.ResetEncoders1_CurrentSetting
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ts_pendulim_P.ResetEncoders_CurrentSetting
	  section.data(2).logicalSrcIdx = 72;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ts_pendulim_B)
    ;%
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% ts_pendulim_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ts_pendulim_B.AngleScale
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% ts_pendulim_B.PendPosOut
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% ts_pendulim_B.Pend_vel
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% ts_pendulim_B.Sum
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% ts_pendulim_B.Sum_f
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% ts_pendulim_B.Cart_pos
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% ts_pendulim_B.Cart_vel
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% ts_pendulim_B.Add
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% ts_pendulim_B.Memory
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% ts_pendulim_B.Sum_h
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% ts_pendulim_B.PWM
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% ts_pendulim_B.Saturation
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% ts_pendulim_B.ResetEncoder
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
	  ;% ts_pendulim_B.ResetSource
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 26;
	
	  ;% ts_pendulim_B.LimitFlag
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 29;
	
	  ;% ts_pendulim_B.LimitFlagSource
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 32;
	
	  ;% ts_pendulim_B.LimitSource
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 35;
	
	  ;% ts_pendulim_B.SetLimit
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 38;
	
	  ;% ts_pendulim_B.LimitSwitch
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 41;
	
	  ;% ts_pendulim_B.PWMPrescaler
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 44;
	
	  ;% ts_pendulim_B.PWMPrescalerSource
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 45;
	
	  ;% ts_pendulim_B.ResetSwitchFlag
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 46;
	
	  ;% ts_pendulim_B.ResetSwitchFlagSource
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 49;
	
	  ;% ts_pendulim_B.ThermFlag
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 52;
	
	  ;% ts_pendulim_B.ThermFlagSource
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 55;
	
	  ;% ts_pendulim_B.ResetEncoders
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 58;
	
	  ;% ts_pendulim_B.FilterCoefficient
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 59;
	
	  ;% ts_pendulim_B.IntegralGain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 60;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ts_pendulim_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% ts_pendulim_DW.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ts_pendulim_DW.Memory1_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ts_pendulim_DW.Memory_PreviousInput_b
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ts_pendulim_DW.PendulumControlandStatesExperiment_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2037341661;
  targMap.checksum1 = 3015900732;
  targMap.checksum2 = 3569414441;
  targMap.checksum3 = 3029458700;

