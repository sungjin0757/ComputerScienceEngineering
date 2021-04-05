
from socket import * 
import sys 
#import ipaddress

#sys.stdin=open('ip_address.txt','rt')
serverSocket = socket(AF_INET, SOCK_STREAM)

accepted_Subnet=[]
for i in range(254):
    accepted_Subnet.append(input())
serverPort = 7777

serverSocket.bind(('', serverPort))

serverSocket.listen(1)
for ip in accepted_Subnet:
    print("인정 받는 서브네트워크 리스트:",ip)
while True:
        print('The server is ready to receive')
        
        connectionSocket, addr = serverSocket.accept()
        
        browser_ip=addr[0]
        browser_ip=browser_ip.split('.')
        browser_ip_binary=[bin(int(i)).split('b')[1]for i in browser_ip]
        for i in range(len(browser_ip_binary)):
                if len(browser_ip_binary[i])<8:
                    tmp=''
                    for j in range(8-len(browser_ip_binary[i])):
                        tmp+='0'
                browser_ip_binary[i]=tmp+browser_ip_binary[i]
        browser_ip_binary=''.join(browser_ip_binary)
    
        browser_net=[]
        browser_host=[]
        k=7
        l=-1
        
        for i in range(4):
            tmp=0
            cnt=0
            for j in range(k,l,-1):
                
                tmp+=(int(browser_ip_binary[j])*(2**cnt))
                cnt+=1
            if k==31:
                browser_net.append('0')
                browser_host.append(str(tmp))
            else:
                browser_net.append(str(tmp))
                browser_host.append('0')
            k+=8
            l+=8
        browser_net='.'.join(browser_net)
        browser_host='.'.join(browser_host)
        print()
        print("Client의 서브 네트워크 : ",browser_net)
        print("Client의 Host : ",browser_host)
        print()
        
        if not(addr[0] in accepted_Subnet):
            print("인정 받지 못한 서브넷!")
            
            continue
        try: 

                message = connectionSocket.recv(2048).decode()
                print(message)

                filename = message.split()[1]
                print(filename)

                myfile = open(filename[1:],'rb')

                response = myfile.read()
                myfile.close()

                header = 'HTTP/1.1 200 OK\n'

                if(filename.endswith(".jpg")):
                        filetype = 'image/jpg'
                elif(filename.endswith(".mp4")):
                        filetype = 'video/mp4'
                elif(filename.endswith(".gif")):
                        filetype = 'image/gif'
                elif(filename.endswith(".wmv")):
                        filetype = 'video/wmv'
                elif(filename.endswith(".txt")):
                        filetype='text/txt'
                else:
                        filetype='text/html'

                header += 'Content-Type: '+str(filetype)+'\n\n'
                print(header)

                connectionSocket.send(header.encode())
                connectionSocket.send(response)
                connectionSocket.close()

        except IOError:
                header = 'HTTP/1.1 404 Not Found\n\n'
                response = '<html><body><center><h3>Error 404: File not found</h3><p>Python HTTP Server</p></center></body></html>'.encode() 

                print(header)
                connectionSocket.send(header.encode())
                connectionSocket.send(response)
                connectionSocket.close()
        
serverSocket.close()
sys.exit()
