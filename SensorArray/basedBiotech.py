import serial
import requests

url = "https://maker.ifttt.com/trigger/environment/json/with/key/fnFy_kYWuLIPV58-SOEFzy91l3PE3VoZjrTSaJUFDwz"
prefixes = {
	"based_airwet" : "H",
	"based_temp" : "T",
	"based_soilwet" : "S"
}


with serial.Serial("COM3", 9600, timeout = 3) as ser:
	while ser.is_open:

		new = str(ser.readline())
		new = new.replace("b'","")
		new = new.replace("\\r", "")
		new = new.replace("\\n", "")
		new = new.replace("'", "")
		
		based_airwet = 0
		based_temp = 0
		based_soilwet = 0

		print(new)

		# if new[1:2] == prefixes["based_airwet"]:
		# 	print("airwet")
		# 	print(new[2:3])
		# 	based_airwet = new[2:3]
		# elif new[1:2] == prefixes["based_temp"]:
		# 	print("temp")
		# 	print(new[2:3])
		# 	based_temp = new[2:3]
		# elif new[1:2] == prefixes["based_soilwet"]:
		# 	print("soilwet")
		# 	print(new[2:3])
		# 	based_soilwet = new[2:3]
		# else:
		# 	print("unknown value") 

		envjson = {"airwet": airwet, "temp": temp, "soilwet": soilwet}

		requests.post(url, json = envjson);
