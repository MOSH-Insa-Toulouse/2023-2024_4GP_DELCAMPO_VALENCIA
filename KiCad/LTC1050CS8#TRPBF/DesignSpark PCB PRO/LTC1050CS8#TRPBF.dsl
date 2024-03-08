SamacSys ECAD Model
879424/1345143/2.50/8/4/Integrated Circuit

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r152.6_65"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.65) (shapeHeight 1.526))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "SOIC127P599X175-8N" (originalName "SOIC127P599X175-8N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r152.6_65) (pt -2.712, 1.905) (rotation 90))
			(pad (padNum 2) (padStyleRef r152.6_65) (pt -2.712, 0.635) (rotation 90))
			(pad (padNum 3) (padStyleRef r152.6_65) (pt -2.712, -0.635) (rotation 90))
			(pad (padNum 4) (padStyleRef r152.6_65) (pt -2.712, -1.905) (rotation 90))
			(pad (padNum 5) (padStyleRef r152.6_65) (pt 2.712, -1.905) (rotation 90))
			(pad (padNum 6) (padStyleRef r152.6_65) (pt 2.712, -0.635) (rotation 90))
			(pad (padNum 7) (padStyleRef r152.6_65) (pt 2.712, 0.635) (rotation 90))
			(pad (padNum 8) (padStyleRef r152.6_65) (pt 2.712, 1.905) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 30)
			(line (pt -3.725 2.752) (pt 3.725 2.752) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 3.725 2.752) (pt 3.725 -2.752) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 3.725 -2.752) (pt -3.725 -2.752) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt -3.725 -2.752) (pt -3.725 2.752) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.95 2.451) (pt 1.95 2.451) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.95 2.451) (pt 1.95 -2.451) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.95 -2.451) (pt -1.95 -2.451) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.95 -2.451) (pt -1.95 2.451) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.95 1.181) (pt -0.68 2.451) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.6 2.451) (pt 1.6 2.451) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.6 2.451) (pt 1.6 -2.451) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.6 -2.451) (pt -1.6 -2.451) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.6 -2.451) (pt -1.6 2.451) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -3.475 2.58) (pt -1.95 2.58) (width 0.2))
		)
	)
	(symbolDef "LTC1050CS8_TRPBF" (originalName "LTC1050CS8_TRPBF")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 0 mils -200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 230 mils -225 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 4) (pt 0 mils -300 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 230 mils -325 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 5) (pt 1700 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 1470 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 6) (pt 1700 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 1470 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 7) (pt 1700 mils -200 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 1470 mils -225 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 8) (pt 1700 mils -300 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 1470 mils -325 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(line (pt 200 mils 100 mils) (pt 1500 mils 100 mils) (width 6 mils))
		(line (pt 1500 mils 100 mils) (pt 1500 mils -400 mils) (width 6 mils))
		(line (pt 1500 mils -400 mils) (pt 200 mils -400 mils) (width 6 mils))
		(line (pt 200 mils -400 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 1550 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "LTC1050CS8#TRPBF" (originalName "LTC1050CS8#TRPBF") (compHeader (numPins 8) (numParts 1) (refDesPrefix IC)
		)
		(compPin "1" (pinName "NC_1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "-IN") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "+IN") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "4" (pinName "V-") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "8" (pinName "NC_2") (partNum 1) (symPinNum 5) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "7" (pinName "V+") (partNum 1) (symPinNum 6) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "6" (pinName "OUT") (partNum 1) (symPinNum 7) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "5" (pinName "EXT CLOCK INPUT") (partNum 1) (symPinNum 8) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "LTC1050CS8_TRPBF"))
		(attachedPattern (patternNum 1) (patternName "SOIC127P599X175-8N")
			(numPads 8)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "4")
				(padNum 5) (compPinRef "5")
				(padNum 6) (compPinRef "6")
				(padNum 7) (compPinRef "7")
				(padNum 8) (compPinRef "8")
			)
		)
		(attr "Manufacturer_Name" "Analog Devices")
		(attr "Manufacturer_Part_Number" "LTC1050CS8#TRPBF")
		(attr "Mouser Part Number" "584-LTC1050CS8#TRPBF")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Analog-Devices/LTC1050CS8TRPBF?qs=hVkxg5c3xu%252BAz6PQseXWvA%3D%3D")
		(attr "Arrow Part Number" "LTC1050CS8#TRPBF")
		(attr "Arrow Price/Stock" "https://www.arrow.com/en/products/ltc1050cs8trpbf/analog-devices?region=nac")
		(attr "Description" "Zero-Drift Amplifier Circuit 8-SO")
		(attr "Datasheet Link" "http://www.linear.com/docs/1770")
		(attr "Height" "1.752 mm")
	)

)
