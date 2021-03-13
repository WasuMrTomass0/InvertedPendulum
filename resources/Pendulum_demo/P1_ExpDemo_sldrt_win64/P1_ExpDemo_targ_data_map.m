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
    ;% Auto data (P1_ExpDemo_P)
    ;%
      section.nData     = 123;
      section.data(123)  = dumData; %prealloc
      
	  ;% P1_ExpDemo_P.RefCartPos_Amplitude
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P1_ExpDemo_P.PIDPend_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% P1_ExpDemo_P.PIDCart_D
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% P1_ExpDemo_P.RefCartPos_Frequency
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% P1_ExpDemo_P.ControllerPID_Friction
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% P1_ExpDemo_P.PIDPend_I
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% P1_ExpDemo_P.PIDCart_I
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% P1_ExpDemo_P.PIDPend_P
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% P1_ExpDemo_P.PIDCart_P
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% P1_ExpDemo_P.Softlandingarbiter_R
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% P1_ExpDemo_P.RefCartPos_Sawtooth
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% P1_ExpDemo_P.RefCartPos_Sine
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% P1_ExpDemo_P.RefCartPos_Square
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% P1_ExpDemo_P.Sensors_T0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% P1_ExpDemo_P.ControllerPID_T0
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% P1_ExpDemo_P.ControllerPID_Umax
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% P1_ExpDemo_P.CoulombViscousFriction_gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% P1_ExpDemo_P.CoulombViscousFriction_gain_h
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% P1_ExpDemo_P.Softlandingarbiter_k
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% P1_ExpDemo_P.CoulombViscousFriction_offset
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% P1_ExpDemo_P.AlfaNormalization_pos
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% P1_ExpDemo_P.Swingingcontroller_umax
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% P1_ExpDemo_P.Linearcontroller1_umax1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% P1_ExpDemo_P.Nottoescapewatchdog_umax2
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% P1_ExpDemo_P.CtrlSat_UpperSat
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% P1_ExpDemo_P.CtrlSat_LowerSat
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% P1_ExpDemo_P.Normal_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% P1_ExpDemo_P.Reset_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% P1_ExpDemo_P._Threshold
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% P1_ExpDemo_P._Threshold_p
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% P1_ExpDemo_P.Encoder_P1_Size
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% P1_ExpDemo_P.Encoder_P1
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 32;
	
	  ;% P1_ExpDemo_P.Encoder_P2_Size
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 33;
	
	  ;% P1_ExpDemo_P.Encoder_P2
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 35;
	
	  ;% P1_ExpDemo_P.Encoder1024PPR_Gain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 36;
	
	  ;% P1_ExpDemo_P.PosCartScale_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 37;
	
	  ;% P1_ExpDemo_P.CartOffset_Value
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 38;
	
	  ;% P1_ExpDemo_P.Gain3_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 39;
	
	  ;% P1_ExpDemo_P.Const1_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 40;
	
	  ;% P1_ExpDemo_P.Const2_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 41;
	
	  ;% P1_ExpDemo_P.Const3_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 42;
	
	  ;% P1_ExpDemo_P.MatrixGain_Gain
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 43;
	
	  ;% P1_ExpDemo_P.pi_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 47;
	
	  ;% P1_ExpDemo_P.AngleScale_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 48;
	
	  ;% P1_ExpDemo_P.Gain1_Gain
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 49;
	
	  ;% P1_ExpDemo_P.Memory_X0
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 50;
	
	  ;% P1_ExpDemo_P.Memory1_X0
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 51;
	
	  ;% P1_ExpDemo_P.Control0_Value
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 52;
	
	  ;% P1_ExpDemo_P.one_Value
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 53;
	
	  ;% P1_ExpDemo_P.swing_OnVal
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 54;
	
	  ;% P1_ExpDemo_P.swing_OffVal
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 55;
	
	  ;% P1_ExpDemo_P.swing_YOn
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 56;
	
	  ;% P1_ExpDemo_P.swing_YOff
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 57;
	
	  ;% P1_ExpDemo_P.Gain1_Gain_f
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 58;
	
	  ;% P1_ExpDemo_P.TransferFcn_A
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 59;
	
	  ;% P1_ExpDemo_P.TransferFcn_C
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 60;
	
	  ;% P1_ExpDemo_P.Gain2_Gain
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 61;
	
	  ;% P1_ExpDemo_P.SaturationCartError_UpperSat
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 62;
	
	  ;% P1_ExpDemo_P.SaturationCartError_LowerSat
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 63;
	
	  ;% P1_ExpDemo_P.Gain3_Gain_e
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 64;
	
	  ;% P1_ExpDemo_P.Gain4_Gain
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 65;
	
	  ;% P1_ExpDemo_P.Integrator_IC
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 66;
	
	  ;% P1_ExpDemo_P.Integrator_UpperSat
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 67;
	
	  ;% P1_ExpDemo_P.Integrator_LowerSat
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 68;
	
	  ;% P1_ExpDemo_P._Threshold_b
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 69;
	
	  ;% P1_ExpDemo_P.AlgorithmSelector2_Amp
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 70;
	
	  ;% P1_ExpDemo_P.AlgorithmSelector2_Period
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 71;
	
	  ;% P1_ExpDemo_P.AlgorithmSelector2_Duty
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 72;
	
	  ;% P1_ExpDemo_P.AlgorithmSelector2_PhaseDelay
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 73;
	
	  ;% P1_ExpDemo_P.Gain1_Gain_g
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 74;
	
	  ;% P1_ExpDemo_P.Integrator_IC_a
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 75;
	
	  ;% P1_ExpDemo_P.Integrator_UpperSat_l
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 76;
	
	  ;% P1_ExpDemo_P.Integrator_LowerSat_k
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 77;
	
	  ;% P1_ExpDemo_P.Memory_X0_p
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 78;
	
	  ;% P1_ExpDemo_P.Gain3_Gain_b
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 79;
	
	  ;% P1_ExpDemo_P.Integrator_IC_h
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 80;
	
	  ;% P1_ExpDemo_P.Integrator_UpperSat_b
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 81;
	
	  ;% P1_ExpDemo_P.Integrator_LowerSat_kg
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 82;
	
	  ;% P1_ExpDemo_P.Memory_X0_m
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 83;
	
	  ;% P1_ExpDemo_P.Switch_Threshold
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 84;
	
	  ;% P1_ExpDemo_P.CtrlSat_UpperSat_o
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 85;
	
	  ;% P1_ExpDemo_P.CtrlSat_LowerSat_l
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 86;
	
	  ;% P1_ExpDemo_P.PWM_P1_Size
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 87;
	
	  ;% P1_ExpDemo_P.PWM_P1
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 89;
	
	  ;% P1_ExpDemo_P.PWM_P2_Size
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 90;
	
	  ;% P1_ExpDemo_P.PWM_P2
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 92;
	
	  ;% P1_ExpDemo_P.Saturation_UpperSat
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 93;
	
	  ;% P1_ExpDemo_P.Saturation_LowerSat
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 94;
	
	  ;% P1_ExpDemo_P.ResetEncoder_P1_Size
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 95;
	
	  ;% P1_ExpDemo_P.ResetEncoder_P1
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 97;
	
	  ;% P1_ExpDemo_P.ResetEncoder_P2_Size
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 98;
	
	  ;% P1_ExpDemo_P.ResetEncoder_P2
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 100;
	
	  ;% P1_ExpDemo_P.ResetSource_Value
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 101;
	
	  ;% P1_ExpDemo_P.LimitFlag_P1_Size
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 104;
	
	  ;% P1_ExpDemo_P.LimitFlag_P1
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 106;
	
	  ;% P1_ExpDemo_P.LimitFlag_P2_Size
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 107;
	
	  ;% P1_ExpDemo_P.LimitFlag_P2
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 109;
	
	  ;% P1_ExpDemo_P.LimitFlagSource_Value
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 110;
	
	  ;% P1_ExpDemo_P.LimitSource_Value
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 113;
	
	  ;% P1_ExpDemo_P.SetLimit_P1_Size
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 116;
	
	  ;% P1_ExpDemo_P.SetLimit_P1
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 118;
	
	  ;% P1_ExpDemo_P.SetLimit_P2_Size
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 119;
	
	  ;% P1_ExpDemo_P.SetLimit_P2
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 121;
	
	  ;% P1_ExpDemo_P.LimitSwitch_P1_Size
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 122;
	
	  ;% P1_ExpDemo_P.LimitSwitch_P1
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 124;
	
	  ;% P1_ExpDemo_P.LimitSwitch_P2_Size
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 125;
	
	  ;% P1_ExpDemo_P.LimitSwitch_P2
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 127;
	
	  ;% P1_ExpDemo_P.PWMPrescaler_P1_Size
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 128;
	
	  ;% P1_ExpDemo_P.PWMPrescaler_P1
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 130;
	
	  ;% P1_ExpDemo_P.PWMPrescaler_P2_Size
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 131;
	
	  ;% P1_ExpDemo_P.PWMPrescaler_P2
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 133;
	
	  ;% P1_ExpDemo_P.PWMPrescalerSource_Value
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 134;
	
	  ;% P1_ExpDemo_P.ResetSwitchFlag_P1_Size
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 135;
	
	  ;% P1_ExpDemo_P.ResetSwitchFlag_P1
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 137;
	
	  ;% P1_ExpDemo_P.ResetSwitchFlag_P2_Size
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 138;
	
	  ;% P1_ExpDemo_P.ResetSwitchFlag_P2
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 140;
	
	  ;% P1_ExpDemo_P.ResetSwitchFlagSource_Value
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 141;
	
	  ;% P1_ExpDemo_P.ThermFlag_P1_Size
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 144;
	
	  ;% P1_ExpDemo_P.ThermFlag_P1
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 146;
	
	  ;% P1_ExpDemo_P.ThermFlag_P2_Size
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 147;
	
	  ;% P1_ExpDemo_P.ThermFlag_P2
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 149;
	
	  ;% P1_ExpDemo_P.ThermFlagSource_Value
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 150;
	
	  ;% P1_ExpDemo_P.IntegratorGain_Gain
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 153;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% P1_ExpDemo_P.ResetEncoders_CurrentSetting
	  section.data(1).logicalSrcIdx = 123;
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
    ;% Auto data (P1_ExpDemo_B)
    ;%
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% P1_ExpDemo_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P1_ExpDemo_B.Sum
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% P1_ExpDemo_B.Cart_pos
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% P1_ExpDemo_B.MatrixGain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% P1_ExpDemo_B.AngleScale
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% P1_ExpDemo_B.PendPosOut
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% P1_ExpDemo_B.Pend_vel
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% P1_ExpDemo_B.Cart_vel
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% P1_ExpDemo_B.Sum_k
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% P1_ExpDemo_B.umax
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 16;
	
	  ;% P1_ExpDemo_B.Fcn
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 17;
	
	  ;% P1_ExpDemo_B.CtrlMode
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 18;
	
	  ;% P1_ExpDemo_B.Gain1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 19;
	
	  ;% P1_ExpDemo_B.Memory
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 20;
	
	  ;% P1_ExpDemo_B.Gain3
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% P1_ExpDemo_B.Memory_o
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% P1_ExpDemo_B.Fcn_k
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 23;
	
	  ;% P1_ExpDemo_B.CtrlSat
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 24;
	
	  ;% P1_ExpDemo_B.PWM
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 25;
	
	  ;% P1_ExpDemo_B.Saturation
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% P1_ExpDemo_B.ResetEncoder
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 31;
	
	  ;% P1_ExpDemo_B.ResetSource
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 36;
	
	  ;% P1_ExpDemo_B.LimitFlag
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 39;
	
	  ;% P1_ExpDemo_B.LimitFlagSource
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 42;
	
	  ;% P1_ExpDemo_B.LimitSource
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 45;
	
	  ;% P1_ExpDemo_B.SetLimit
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 48;
	
	  ;% P1_ExpDemo_B.LimitSwitch
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 51;
	
	  ;% P1_ExpDemo_B.PWMPrescaler
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 54;
	
	  ;% P1_ExpDemo_B.PWMPrescalerSource
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 55;
	
	  ;% P1_ExpDemo_B.ResetSwitchFlag
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 56;
	
	  ;% P1_ExpDemo_B.ResetSwitchFlagSource
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 59;
	
	  ;% P1_ExpDemo_B.ThermFlag
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 62;
	
	  ;% P1_ExpDemo_B.ThermFlagSource
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 65;
	
	  ;% P1_ExpDemo_B.Fcn_kz
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 68;
	
	  ;% P1_ExpDemo_B.IntegratorGain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 69;
	
	  ;% P1_ExpDemo_B.ResetEncoders
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 70;
	
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
    nTotSects     = 4;
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
    ;% Auto data (P1_ExpDemo_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% P1_ExpDemo_DW.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P1_ExpDemo_DW.Memory1_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% P1_ExpDemo_DW.Memory_PreviousInput_a
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% P1_ExpDemo_DW.Memory_PreviousInput_o
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% P1_ExpDemo_DW.CartRef_Pos_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P1_ExpDemo_DW.PendulumControlandStatesExperiment_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% P1_ExpDemo_DW.SoftLandingMonitor_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% P1_ExpDemo_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% P1_ExpDemo_DW.swing_Mode
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
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


  targMap.checksum0 = 881090505;
  targMap.checksum1 = 87551531;
  targMap.checksum2 = 1747452531;
  targMap.checksum3 = 1592601213;

