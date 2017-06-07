#include "StringStream.h"

String StringStream::readStringUntil(char terminator) {
	if (available() > 0) {
		int index = string.indexOf(terminator, position);
		if (index >= 0) {
			int currPos = position;
			position = index + 1;
			return string.substring(currPos, index);
		}
		else {
			int currPos = position;
			position = string.length();
			return string.substring(currPos);
		}
	}
	else {
		return "";
	}
}

