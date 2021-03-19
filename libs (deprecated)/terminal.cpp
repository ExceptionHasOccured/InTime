String terminal() {
	if (Serial.available() > 0) {
		String s = Serial.read();
		if(getArg(s, " ", 0) == "timer") {
			switch(getArg(s, " ", 1)){
				case "-s":
					return "start:0";
					break;
				case "-e":
					return "interupt:0";
					break;
				case "-t":
					return "setTime:" + getArg(s, " ", 2);
					break;
				default:
					return "null";
					break;
			}
		}
		else {
			Serial.println("Invalid syntax. Check documentation for more information.");
		}
	}
}

String getArg(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}