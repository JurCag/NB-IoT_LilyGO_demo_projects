import gfy_serial as gfys
import serial, sys

# To work the AT_debug_demo code must be uploaded to the baord

try:
    ser = serial.Serial('com4', baudrate=115200, timeout=0.1)
except serial.serialutil.SerialException:
    print(f"Close the port first!")
    sys.exit(1)

print('Empty AT command, expects "OK" reply')
gfys.write_at_cmd(ser, "AT")
gfys.read_at_cmd(ser, "str")

print("Report Mobile Equipment Error")
gfys.write_at_cmd(ser, "AT+CMEE=0")
gfys.read_at_cmd(ser, "str")

print("Version information")
gfys.write_at_cmd(ser, "AT+SIMCOMATI")
gfys.read_at_cmd(ser, "str")

print("Query the SIM card status")
gfys.write_at_cmd(ser, "AT+CPIN?")
gfys.read_at_cmd(ser, "str")

print("Network Registration Status")
gfys.write_at_cmd(ser, "AT+CGREG?")
gfys.read_at_cmd(ser, "str")

print("Network signal quality query")
gfys.write_at_cmd(ser, "AT+CSQ")
gfys.read_at_cmd(ser, "str")

print("Querying current Carrier Information")
gfys.write_at_cmd(ser, "AT+COPS?")
gfys.read_at_cmd(ser, "str")

ser.close()


