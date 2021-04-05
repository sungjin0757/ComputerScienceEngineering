from socket import * 
import sys 
import threading
import ThreadGen as thread

serverSocket = socket(AF_INET, SOCK_STREAM)

serverPort = 7777

serverSocket.bind(('', serverPort))

threads=[]
cnt=0
while True:
        print('The server is ready to receive')
        serverSocket.listen(4)

        connectionSocket, addr = serverSocket.accept()
        
        newthread=thread.ClientThread(connectionSocket,addr,str(cnt))
        print(type(addr[0]))
        threads.append(newthread)
        cnt+=1
        newthread.start()
      
for t in threads:
    t.join()

serverSocket.close()
sys.exit()

