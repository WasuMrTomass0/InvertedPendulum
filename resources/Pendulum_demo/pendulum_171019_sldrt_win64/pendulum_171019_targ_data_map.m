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
    ;% Auto data (pendulum_171019_P)
    ;%
      section.nData     = 58;
      section.data(58)  = dumData; %prealloc
      
	  ;% pendulum_171019_P.Sensors_T0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendulum_171019_P.AlfaNormalization_pos
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendulum_171019_P.Normal_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pendulum_171019_P.Reset_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% pendulum_171019_P.Control_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% pendulum_171019_P.Encoder_P1_Size
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% pendulum_171019_P.Encoder_P1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% pendulum_171019_P.Encoder_P2_Size
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% pendulum_171019_P.Encoder_P2
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% pendulum_171019_P.Encoder500PPR_Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% pendulum_171019_P.PosCartScale_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% pendulum_171019_P.CartOffset_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% pendulum_171019_P.Gain3_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% pendulum_171019_P.Memory1_X0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% pendulum_171019_P.pi_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% pendulum_171019_P.AngleScale_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% pendulum_171019_P.Gain1_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% pendulum_171019_P.Memory_X0
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% pendulum_171019_P.PWM_P1_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% pendulum_171019_P.PWM_P1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% pendulum_171019_P.PWM_P2_Size
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% pendulum_171019_P.PWM_P2
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% pendulum_171019_P.Saturation_UpperSat
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% pendulum_171019_P.Saturation_LowerSat
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% pendulum_171019_P.ResetEncoder_P1_Size
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% pendulum_171019_P.ResetEncoder_P1
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 30;
	
	  ;% pendulum_171019_P.ResetEncoder_P2_Size
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 31;
	
	  ;% pendulum_171019_P.ResetEncoder_P2
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 33;
	
	  ;% pendulum_171019_P.ResetSource_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 34;
	
	  ;% pendulum_171019_P.LimitFlag_P1_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 37;
	
	  ;% pendulum_171019_P.LimitFlag_P1
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 39;
	
	  ;% pendulum_171019_P.LimitFlag_P2_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 40;
	
	  ;% pendulum_171019_P.LimitFlag_P2
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 42;
	
	  ;% pendulum_171019_P.LimitFlagSource_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 43;
	
	  ;% pendulum_171019_P.LimitSource_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 46;
	
	  ;% pendulum_171019_P.SetLimit_P1_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 49;
	
	  ;% pendulum_171019_P.SetLimit_P1
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 51;
	
	  ;% pendulum_171019_P.SetLimit_P2_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 52;
	
	  ;% pendulum_171019_P.SetLimit_P2
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 54;
	
	  ;% pendulum_171019_P.LimitSwitch_P1_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 55;
	
	  ;% pendulum_171019_P.LimitSwitch_P1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 57;
	
	  ;% pendulum_171019_P.LimitSwitch_P2_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 58;
	
	  ;% pendulum_171019_P.LimitSwitch_P2
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 60;
	
	  ;% pendulum_171019_P.PWMPrescaler_P1_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 61;
	
	  ;% pendulum_171019_P.PWMPrescaler_P1
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 63;
	
	  ;% pendulum_171019_P.PWMPrescaler_P2_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 64;
	
	  ;% pendulum_171019_P.PWMPrescaler_P2
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 66;
	
	  ;% pendulum_171019_P.PWMPrescalerSource_Value
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 67;
	
	  ;% pendulum_171019_P.ResetSwitchFlag_P1_Size
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 68;
	
	  ;% pendulum_171019_P.ResetSwitchFlag_P1
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 70;
	
	  ;% pendulum_171019_P.ResetSwitchFlag_P2_Size
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 71;
	
	  ;% pendulum_171019_P.ResetSwitchFlag_P2
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 73;
	
	  ;% pendulum_171019_P.ResetSwitchFlagSource_Value
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 74;
	
	  ;% pendulum_171019_P.ThermFlag_P1_Size
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 77;
	
	  ;% pendulum_171019_P.ThermFlag_P1
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 79;
	
	  ;% pendulum_171019_P.ThermFlag_P2_Size
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 80;
	
	  ;% pendulum_171019_P.ThermFlag_P2
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 82;
	
	  ;% pendulum_171019_P.ThermFlagSource_Value
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 83;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% pendulum_171019_P.ResetEncoders_CurrentSetting
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
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
    ;% Auto data (pendulum_171019_B)
    ;%
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% pendulum_171019_B.Control
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendulum_171019_B.Encoder
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendulum_171019_B.Sum
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% pendulum_171019_B.Cart_pos
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% pendulum_171019_B.Cart_vel
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% pendulum_171019_B.AngleScale
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% pendulum_171019_B.PendPosOut
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% pendulum_171019_B.Pend_vel
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% pendulum_171019_B.PWM
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% pendulum_171019_B.Saturation
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% pendulum_171019_B.ResetEncoder
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 18;
	
	  ;% pendulum_171019_B.ResetSource
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 23;
	
	  ;% pendulum_171019_B.LimitFlag
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 26;
	
	  ;% pendulum_171019_B.LimitFlagSource
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 29;
	
	  ;% pendulum_171019_B.LimitSource
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 32;
	
	  ;% pendulum_171019_B.SetLimit
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 35;
	
	  ;% pendulum_171019_B.LimitSwitch
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 38;
	
	  ;% pendulum_171019_B.PWMPrescaler
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 41;
	
	  ;% pendulum_171019_B.PWMPrescalerSource
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 42;
	
	  ;% pendulum_171019_B.ResetSwitchFlag
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 43;
	
	  ;% pendulum_171019_B.ResetSwitchFlagSource
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 46;
	
	  ;% pendulum_171019_B.ThermFlag
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 49;
	
	  ;% pendulum_171019_B.ThermFlagSource
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 52;
	
	  ;% pendulum_171019_B.ResetEncoders
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 55;
	
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
    ;% Auto data (pendulum_171019_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pendulum_171019_DW.Memory1_PreviousInput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendulum_171019_DW.Memory_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% pendulum_171019_DW.PendulumControlandStatesExperiment_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 2;
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


  targMap.checksum0 = 1797003332;
  targMap.checksum1 = 2179790002;
  targMap.checksum2 = 3767939128;
  targMap.checksum3 = 1434986208;

