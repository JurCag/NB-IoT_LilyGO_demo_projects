import serial


def write_at_cmd(ser, at_cmd="AT", format="bytes"):
    AT_cmd = (at_cmd + "\r\n").encode()
    if format == "str":
        print(AT_cmd.decode())
    else:
        print(AT_cmd)
    ser.write(AT_cmd)

def read_at_cmd(ser, format="bytes"):
    eol_OK = b'OK\r\n'
    leneol_OK = len(eol_OK)

    eol_ERROR = b'ERROR\r\n'
    leneol_ERROR = len(eol_ERROR)

    line = bytearray()
    while True:
        c = ser.read(1)
        if c:
            line += c
            if line[-leneol_OK:] == eol_OK:
                break
            if line[-leneol_ERROR:] == eol_ERROR:
                break
        else:
            break

    if format == "str":
        print(line.decode())
    else:
        print(bytes(line))

if __name__ == "__main__":
    print('')