from socket import * 
import sys 
import threading
class ClientThread(threading.Thread):

    def __init__(self,connectionSocket,addr,name):
        threading.Thread.__init__(self)

        self.name=name
        self.addr = addr
        self.connectionSocket=connectionSocket
    def run(self):    
        try: 

                message = self.connectionSocket.recv(2048).decode()
        
                #print(message)
               
                filename = message.split()[1]
                
                #print(filename)
                
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
                
                #print(header)
                print("Thread",threading.currentThread().getName(),"실행!")
                print()
                self.connectionSocket.send(header.encode())
                self.connectionSocket.send(response)
                self.connectionSocket.close()

        except IOError:
                header = 'HTTP/1.1 404 Not Found\n\n'
                response = '<html><body><center><h3>Error 404: File not found</h3><p>Python HTTP Server</p></center></body></html>'.encode() 

                
                #print(header)
               
                print("Thread",threading.currentThread().getName(),"실행!")
                self.connectionSocket.send(header.encode())
                self.connectionSocket.send(response)
                self.connectionSocket.close()
        
