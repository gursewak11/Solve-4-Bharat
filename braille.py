import serial
import time
import pyttsx3 
import re
import autocomplete

ser = serial.Serial('COM18', 9600, timeout=1)  # open serial port, set time out equals 1s
print(ser.is_open)
print(ser.name)
autocomplete.load()
engine = pyttsx3.init() 
engine.setProperty('rate', 130)
string=''
string_check= re.compile('[@_!#$%^&*()<>?/\,|}{~:]')
while True:
	data=ser.read().decode('ascii')
	if(data):
		if(data.isalpha() or data.isnumeric() or string_check.search(data) or data==' ' or data=='\n'):
			string+=data
			print(string)
			engine.say(string) 
			engine.runAndWait()
			suggestions = autocomplete.predict('the',string)
			try:
				print(suggestions[0][0])
				engine.say(suggestions[0][0])
				print(suggestions[1][0])
				engine.say(suggestions[1][0])
			except:
				print("No Suggestions")
			engine.runAndWait()
				
			
