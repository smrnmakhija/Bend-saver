import smtplib
import serial
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
from email import encoders
 
fromaddr = "smrnmakhija"
toaddr = "smrnmakhija"
gmail_user = 'smrnmakhija@gmail.com'  
gmail_password = 'bluefrog123'
msg = MIMEMultipart()
 
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = "law violated"
 
body = "Overspeeding"
 
msg.attach(MIMEText(body, 'plain'))
 
filename = "data.txt"
attachment = open("/home/smrnmakhija/i1.png", "rb")
 
part = MIMEBase('application', 'octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition', "attachment; filename= %s" % filename)

msg.attach(part)

usbp='/dev/ttyACM0'
ser1= serial.Serial(usbp,9600)
while(1):
	speed= ser1.readline().strip().decode()
	if (speed>20):
		
		try:  
    			server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
    			server.ehlo()
    			server.login(gmail_user, gmail_password)
    			server.sendmail(sent_from, to, email_text)
    			server.close()

    			print 'Email sent!'
		except:  
    			print 'Something went wrong...'


