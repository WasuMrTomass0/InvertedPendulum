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
    ;% Auto data (pendulim_exp_demoDemo_P)
    ;%
      section.nData     = 124;
      section.data(124)  = dumData; %prealloc
      
	  ;% pendulim_exp_demoDemo_P.RefCartPos_Amplitude
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendulim_exp_demoDemo_P.PIDPend_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendulim_exp_demoDemo_P.PIDCart_D
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pendulim_exp_demoDemo_P.RefCartPos_Frequency
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% pendulim_exp_demoDemo_P.ControllerPID_Friction
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% pendulim_exp_demoDemo_P.PIDPend_I
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% pendulim_exp_demoDemo_P.PIDCart_I
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% pendulim_exp_demoDemo_P.PIDPend_P
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% pendulim_exp_demoDemo_P.PIDCart_P
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% pendulim_exp_demoDemo_P.Softlandingarbiter_R
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% pendulim_exp_demoDemo_P.RefCartPos_Sawtooth
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% pendulim_exp_demoDemo_P.RefCartPos_Sine
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% pendulim_exp_demoDemo_P.RefCartPos_Square
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% pendulim_exp_demoDemo_P.Sensors_T0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% pendulim_exp_demoDemo_P.ControllerPID_T0
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% pendulim_exp_demoDemo_P.ControllerPID_Umax
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% pendulim_exp_demoDemo_P.CoulombViscousFriction_gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% pendulim_exp_demoDemo_P.CoulombViscousFriction_gain_h
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% pendulim_exp_demoDemo_P.Softlandingarbiter_k
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% pendulim_exp_demoDemo_P.CoulombViscousFriction_offset
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% pendulim_exp_demoDemo_P.AlfaNormalization_pos
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% pendulim_exp_demoDemo_P.Swingingcontroller_umax
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% pendulim_exp_demoDemo_P.Linearcontroller1_umax1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% pendulim_exp_demoDemo_P.Nottoescapewatchdog_umax2
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% pendulim_exp_demoDemo_P.CtrlSat_UpperSat
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% pendulim_exp_demoDemo_P.CtrlSat_LowerSat
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% pendulim_exp_demoDemo_P.Normal_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% pendulim_exp_demoDemo_P.Reset_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% pendulim_exp_demoDemo_P._Threshold
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% pendulim_exp_demoDemo_P._Threshold_p
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% pendulim_exp_demoDemo_P.Encoder_P1_Size
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% pendulim_exp_demoDemo_P.Encoder_P1
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 32;
	
	  ;% pendulim_exp_demoDemo_P.Encoder_P2_Size
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 33;
	
	  ;% pendulim_exp_demoDemo_P.Encoder_P2
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 35;
	
	  ;% pendulim_exp_demoDemo_P.Encoder1024PPR_Gain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 36;
	
	  ;% pendulim_exp_demoDemo_P.PosCartScale_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 37;
	
	  ;% pendulim_exp_demoDemo_P.CartOffset_Value
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 38;
	
	  ;% pendulim_exp_demoDemo_P.Gain3_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 39;
	
	  ;% pendulim_exp_demoDemo_P.Const1_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 40;
	
	  ;% pendulim_exp_demoDemo_P.Const2_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 41;
	
	  ;% pendulim_exp_demoDemo_P.Const3_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 42;
	
	  ;% pendulim_exp_demoDemo_P.MatrixGain_Gain
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 43;
	
	  ;% pendulim_exp_demoDemo_P.pi_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 47;
	
	  ;% pendulim_exp_demoDemo_P.AngleScale_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 48;
	
	  ;% pendulim_exp_demoDemo_P.Gain1_Gain
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 49;
	
	  ;% pendulim_exp_demoDemo_P.Memory_X0
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 50;
	
	  ;% pendulim_exp_demoDemo_P.Memory1_X0
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 51;
	
	  ;% pendulim_exp_demoDemo_P.Control0_Value
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 52;
	
	  ;% pendulim_exp_demoDemo_P.one_Value
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 53;
	
	  ;% pendulim_exp_demoDemo_P.swing_OnVal
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 54;
	
	  ;% pendulim_exp_demoDemo_P.swing_OffVal
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 55;
	
	  ;% pendulim_exp_demoDemo_P.swing_YOn
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 56;
	
	  ;% pendulim_exp_demoDemo_P.swing_YOff
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 57;
	
	  ;% pendulim_exp_demoDemo_P.Gain1_Gain_f
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 58;
	
	  ;% pendulim_exp_demoDemo_P.TransferFcn_A
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 59;
	
	  ;% pendulim_exp_demoDemo_P.TransferFcn_C
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 60;
	
	  ;% pendulim_exp_demoDemo_P.Gain2_Gain
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 61;
	
	  ;% pendulim_exp_demoDemo_P.SaturationCartError_UpperSat
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 62;
	
	  ;% pendulim_exp_demoDemo_P.SaturationCartError_LowerSat
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 63;
	
	  ;% pendulim_exp_demoDemo_P.Gain3_Gain_e
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 64;
	
	  ;% pendulim_exp_demoDemo_P.Gain4_Gain
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 65;
	
	  ;% pendulim_exp_demoDemo_P.Integrator_IC
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 66;
	
	  ;% pendulim_exp_demoDemo_P.Integrator_UpperSat
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 67;
	
	  ;% pendulim_exp_demoDemo_P.Integrator_LowerSat
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 68;
	
	  ;% pendulim_exp_demoDemo_P._Threshold_b
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 69;
	
	  ;% pendulim_exp_demoDemo_P.AlgorithmSelector2_Amp
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 70;
	
	  ;% pendulim_exp_demoDemo_P.AlgorithmSelector2_Period
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 71;
	
	  ;% pendulim_exp_demoDemo_P.AlgorithmSelector2_Duty
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 72;
	
	  ;% pendulim_exp_demoDemo_P.AlgorithmSelector2_PhaseDelay
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 73;
	
	  ;% pendulim_exp_demoDemo_P.Gain1_Gain_g
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 74;
	
	  ;% pendulim_exp_demoDemo_P.Integrator_IC_a
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 75;
	
	  ;% pendulim_exp_demoDemo_P.Integrator_UpperSat_l
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 76;
	
	  ;% pendulim_exp_demoDemo_P.Integrator_LowerSat_k
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 77;
	
	  ;% pendulim_exp_demoDemo_P.Memory_X0_p
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 78;
	
	  ;% pendulim_exp_demoDemo_P.Gain3_Gain_b
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 79;
	
	  ;% pendulim_exp_demoDemo_P.Integrator_IC_h
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 80;
	
	  ;% pendulim_exp_demoDemo_P.Integrator_UpperSat_b
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 81;
	
	  ;% pendulim_exp_demoDemo_P.Integrator_LowerSat_kg
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 82;
	
	  ;% pendulim_exp_demoDemo_P.Memory_X0_m
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 83;
	
	  ;% pendulim_exp_demoDemo_P.Switch_Threshold
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 84;
	
	  ;% pendulim_exp_demoDemo_P.CtrlSat_UpperSat_o
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 85;
	
	  ;% pendulim_exp_demoDemo_P.CtrlSat_LowerSat_l
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 86;
	
	  ;% pendulim_exp_demoDemo_P.PWM_P1_Size
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 87;
	
	  ;% pendulim_exp_demoDemo_P.PWM_P1
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 89;
	
	  ;% pendulim_exp_demoDemo_P.PWM_P2_Size
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 90;
	
	  ;% pendulim_exp_demoDemo_P.PWM_P2
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 92;
	
	  ;% pendulim_exp_demoDemo_P.Normal1_Value
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 93;
	
	  ;% pendulim_exp_demoDemo_P.Saturation_UpperSat
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 94;
	
	  ;% pendulim_exp_demoDemo_P.Saturation_LowerSat
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 95;
	
	  ;% pendulim_exp_demoDemo_P.ResetEncoder_P1_Size
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 96;
	
	  ;% pendulim_exp_demoDemo_P.ResetEncoder_P1
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 98;
	
	  ;% pendulim_exp_demoDemo_P.ResetEncoder_P2_Size
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 99;
	
	  ;% pendulim_exp_demoDemo_P.ResetEncoder_P2
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 101;
	
	  ;% pendulim_exp_demoDemo_P.ResetSource_Value
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 102;
	
	  ;% pendulim_exp_demoDemo_P.LimitFlag_P1_Size
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 105;
	
	  ;% pendulim_exp_demoDemo_P.LimitFlag_P1
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 107;
	
	  ;% pendulim_exp_demoDemo_P.LimitFlag_P2_Size
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 108;
	
	  ;% pendulim_exp_demoDemo_P.LimitFlag_P2
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 110;
	
	  ;% pendulim_exp_demoDemo_P.LimitFlagSource_Value
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 111;
	
	  ;% pendulim_exp_demoDemo_P.LimitSource_Value
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 114;
	
	  ;% pendulim_exp_demoDemo_P.SetLimit_P1_Size
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 117;
	
	  ;% pendulim_exp_demoDemo_P.SetLimit_P1
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 119;
	
	  ;% pendulim_exp_demoDemo_P.SetLimit_P2_Size
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 120;
	
	  ;% pendulim_exp_demoDemo_P.SetLimit_P2
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 122;
	
	  ;% pendulim_exp_demoDemo_P.LimitSwitch_P1_Size
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 123;
	
	  ;% pendulim_exp_demoDemo_P.LimitSwitch_P1
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 125;
	
	  ;% pendulim_exp_demoDemo_P.LimitSwitch_P2_Size
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 126;
	
	  ;% pendulim_exp_demoDemo_P.LimitSwitch_P2
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 128;
	
	  ;% pendulim_exp_demoDemo_P.PWMPrescaler_P1_Size
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 129;
	
	  ;% pendulim_exp_demoDemo_P.PWMPrescaler_P1
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 131;
	
	  ;% pendulim_exp_demoDemo_P.PWMPrescaler_P2_Size
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 132;
	
	  ;% pendulim_exp_demoDemo_P.PWMPrescaler_P2
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 134;
	
	  ;% pendulim_exp_demoDemo_P.PWMPrescalerSource_Value
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 135;
	
	  ;% pendulim_exp_demoDemo_P.ResetSwitchFlag_P1_Size
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 136;
	
	  ;% pendulim_exp_demoDemo_P.ResetSwitchFlag_P1
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 138;
	
	  ;% pendulim_exp_demoDemo_P.ResetSwitchFlag_P2_Size
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 139;
	
	  ;% pendulim_exp_demoDemo_P.ResetSwitchFlag_P2
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 141;
	
	  ;% pendulim_exp_demoDemo_P.ResetSwitchFlagSource_Value
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 142;
	
	  ;% pendulim_exp_demoDemo_P.ThermFlag_P1_Size
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 145;
	
	  ;% pendulim_exp_demoDemo_P.ThermFlag_P1
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 147;
	
	  ;% pendulim_exp_demoDemo_P.ThermFlag_P2_Size
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 148;
	
	  ;% pendulim_exp_demoDemo_P.ThermFlag_P2
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 150;
	
	  ;% pendulim_exp_demoDemo_P.ThermFlagSource_Value
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 151;
	
	  ;% pendulim_exp_demoDemo_P.IntegratorGain_Gain
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 154;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pendulim_exp_demoDemo_P.ResetEncoders1_CurrentSetting
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendulim_exp_demoDemo_P.ResetEncoders_CurrentSetting
	  section.data(2).logicalSrcIdx = 125;
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
    ;% Auto data (pendulim_exp_demoDemo_B)
    ;%
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% pendulim_exp_demoDemo_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendulim_exp_demoDemo_B.Sum
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% pendulim_exp_demoDemo_B.Cart_pos
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% pendulim_exp_demoDemo_B.MatrixGain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% pendulim_exp_demoDemo_B.AngleScale
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% pendulim_exp_demoDemo_B.PendPosOut
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% pendulim_exp_demoDemo_B.Pend_vel
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% pendulim_exp_demoDemo_B.Cart_vel
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% pendulim_exp_demoDemo_B.Sum_k
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% pendulim_exp_demoDemo_B.umax
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 16;
	
	  ;% pendulim_exp_demoDemo_B.Fcn
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 17;
	
	  ;% pendulim_exp_demoDemo_B.CtrlMode
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 18;
	
	  ;% pendulim_exp_demoDemo_B.Gain1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 19;
	
	  ;% pendulim_exp_demoDemo_B.Memory
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 20;
	
	  ;% pendulim_exp_demoDemo_B.Gain3
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% pendulim_exp_demoDemo_B.Memory_o
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% pendulim_exp_demoDemo_B.Fcn_k
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 23;
	
	  ;% pendulim_exp_demoDemo_B.CtrlSat
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 24;
	
	  ;% pendulim_exp_demoDemo_B.PWM
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 25;
	
	  ;% pendulim_exp_demoDemo_B.Saturation
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% pendulim_exp_demoDemo_B.ResetEncoder
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 31;
	
	  ;% pendulim_exp_demoDemo_B.ResetSource
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 36;
	
	  ;% pendulim_exp_demoDemo_B.LimitFlag
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 39;
	
	  ;% pendulim_exp_demoDemo_B.LimitFlagSource
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 42;
	
	  ;% pendulim_exp_demoDemo_B.LimitSource
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 45;
	
	  ;% pendulim_exp_demoDemo_B.SetLimit
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 48;
	
	  ;% pendulim_exp_demoDemo_B.LimitSwitch
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 51;
	
	  ;% pendulim_exp_demoDemo_B.PWMPrescaler
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 54;
	
	  ;% pendulim_exp_demoDemo_B.PWMPrescalerSource
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 55;
	
	  ;% pendulim_exp_demoDemo_B.ResetSwitchFlag
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 56;
	
	  ;% pendulim_exp_demoDemo_B.ResetSwitchFlagSource
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 59;
	
	  ;% pendulim_exp_demoDemo_B.ThermFlag
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 62;
	
	  ;% pendulim_exp_demoDemo_B.ThermFlagSource
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 65;
	
	  ;% pendulim_exp_demoDemo_B.Fcn_kz
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 68;
	
	  ;% pendulim_exp_demoDemo_B.IntegratorGain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 69;
	
	  ;% pendulim_exp_demoDemo_B.ResetEncoders
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
    ;% Auto data (pendulim_exp_demoDemo_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% pendulim_exp_demoDemo_DW.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendulim_exp_demoDemo_DW.Memory1_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendulim_exp_demoDemo_DW.Memory_PreviousInput_a
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pendulim_exp_demoDemo_DW.Memory_PreviousInput_o
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% pendulim_exp_demoDemo_DW.CartRef_Pos_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendulim_exp_demoDemo_DW.PendulumControlandStatesExperiment_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendulim_exp_demoDemo_DW.SoftLandingMonitor_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% pendulim_exp_demoDemo_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% pendulim_exp_demoDemo_DW.swing_Mode
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


  targMap.checksum0 = 1021300407;
  targMap.checksum1 = 2571267051;
  targMap.checksum2 = 886309248;
  targMap.checksum3 = 4057273003;

