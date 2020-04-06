import socket
import os
import math
import datetime


log_file = open('python_eth_log.txt', 'w')
print(os.path.realpath(log_file.name))



def main():

    try:
        go_again = int(input('begin? (0=n;1=y): '))
    except:
        print('invalid input, closing')
        go_again = 0
    samples = get_sin_data(11, 8, 1)
    while(go_again != 0):
        
        send_UDP(samples)

        go_again = 1
        #try:
        #    go_again = int(input('another set? (0=n;1=y): '))
        #except:
        #    print('invalid input, closing')
        #    go_again = 0
    


def send_UDP(data_to_send):
    
    # embedded device found with
    # cmd prompt > arp -a
    # hard coded into main.c

    UDP_IP = "169.254.255.255"
    UDP_PORT = 0xBEEF
    MESSAGE = bytes(data_to_send)

    log_file.write('opening socket: ' + UDP_IP + ' : ' + str(UDP_PORT) + '\n')

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))


def get_sin_data(N_exp, data_width, cycles):
    log_file.write('=========================================\n')
    log_file.write(str(datetime.datetime.now().time()) + '\n')
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