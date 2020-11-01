flash:
	./bin/arduino-cli compile --fqbn arduino:avr:uno .
	./bin/arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno .

serial:
	cat /dev/ttyACM0

fmt:
	indent doorbell.ino
