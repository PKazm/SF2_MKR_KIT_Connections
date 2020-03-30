import pdb
import math
import serial


log_file = open('python_uart_log.txt', 'w')

ser = serial.Serial()

def main():
    uart_init()
    ser.open()

    go_again = 1

    while(go_again != 0):
        samples = get_sin_data(8, 8, 50)
        for i in samples:
            print(ser.write(i))

        try:
            go_again = int(input('another set?: '))
        except:
            pass

    ser.close()



def uart_init():
    ser.baudrate = 921600
    ser.port = 'COM11'


def get_sin_data(N_exp, data_width, cycles):
    log_file.write('=========================================\n')
    log_file.write('get_sin_data: ' + str(N_exp) + ', ' + str(data_width) + ', ' + str(cycles) + '\n')
    sin_samples = []
    data_cnt = 2**(N_exp)

    for i in range(0, data_cnt):
        sin_val = math.sin(2*math.pi*cycles*i/data_cnt)
        sin_val = round(sin_val * (2 ** (data_width - 1)))
        log_file.write('sin_val of ' + str(i) + ': ' + str(sin_val) + '\n')
        sin_samples.append(sin_val)

    log_file.write('get_sin_data finished\n')
    log_file.write('=========================================\n')
    return sin_samples


main()
log_file.close()