from socket import *
import time

serverName = '127.0.0.1'

serverPort = 12000


clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(1)
dropPacket=0.0
Packetnumber=0.0
tmp=[]
error=0.0
cnt=0
sum=0.0
for i in range(1,3001):

    message="Ping #" +str(i)
    start=time.time()
    clientSocket.sendto(message.encode(), (serverName, serverPort))

    try:
        modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
        end=time.time()-start
        end=float("{0:.4f}".format(end))
        error=float("{0:.2f}".format((dropPacket/i)*100))
        sum+=end
        print(modifiedMessage.decode(),' ','Seq : ',i,' 에러율 : ',error,'%  RTT : ',end,'sec')
    except timeout:
        dropPacket+=1
        print(i,"번 Request 누락")
        tmp.append(i)
    
    
print()
if tmp:
    for i in range(len(tmp)):
        print(tmp[i],end=', ')
        cnt+=1
    print('번들이 누락 되었습니다.')
    print()
    print('총 에러의 개수는 %d개 이고 총 에러율은 %.2f 입니다.'%(cnt,error))
print('평균 지연시간 : %.3f'%(sum/(3000-dropPacket)))

    
clientSocket.close()

