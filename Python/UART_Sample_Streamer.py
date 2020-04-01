import sys
import pdb
import math
import serial


log_file = open('python_uart_log.txt', 'w')

ser = serial.Serial()

def main():
    uart_init()
    try:
        ser.open()
    except:
        print('serial port not openable')
        return

    try:
        go_again = int(input('begin? (0=n;1=y): '))
    except:
        print('invalid input, closing')
        go_again = 0

    while(go_again != 0):
        samples = get_sin_data(8, 8, 50)
        print(ser.write(samples))
        #for i in samples:
        #    print(ser.write(i))

        try:
            go_again = int(input('another set? (0=n;1=y): '))
        except:
            print('invalid input, closing')
            go_again = 0

    ser.close()



def uart_init():
    try:
        baud = int(input('baudrate (921600): '))
    except:
        sys.exit('invalid baudrate, closing')

    if(baud == 0):
        ser.baudrate = 921600
    else:
        ser.baudrate = baud

    com = input('COM port? (COM11): ')
    if(com == '0'):
        ser.port = 'COM11'
    else:
        ser.port = com


def get_sin_data(N_exp, data_width, cycles):
    log_file.write('=========================================\n')
    log_file.write('get_sin_data: ' + str(N_exp) + ', ' + str(data_width) + ', ' + str(cycles) + '\n')
    sin_samples = []
    data_cnt = 2**(N_exp)

    for i in range(0, data_cnt):
        sin_val = math.sin(2*math.pi*cycles*i/data_cnt)
        sin_val = round(sin_val * (2 ** (data_width - 1) - 1) + (2 ** (data_width - 1) - 1))
        log_file.write('sin_val of ' + str(i) + ': ' + str(sin_val) + '\n')
        sin_samples.append(sin_val)

    log_file.write('min: ' + str(min(sin_samples)) + ', max: ' + str(max(sin_samples)) + '\n')
    log_file.write('get_sin_data finished\n')
    log_file.write('=========================================\n')
    return sin_samples


main()
log_file.close()
