import smtplib
import serial

gmail_user = 'smrnmakhija@gmail.com'  
gmail_password = 'bluefrog123'

sent_from = gmail_user  
to = ['smrnmakhija@gmail.com', 'bill@gmail.com']  


try:
    import Image
except ImportError:
    from PIL import Image
import pytesseract
st=pytesseract.image_to_string(Image.open('/home/smrnmakhija/no.png'))
print(st)
#st=pytesseract.image_to_string(Image.open('/home/smrnmakhija/num.png'), lang='eng'))

subject = 'Rule violation:Overspeeding'
body = st

email_text = """\  
From: %s  
To: %s  
Subject: %s

%s
""" % (sent_from, ", ".join(to), subject, body)

usbp='/dev/ttyACM1'
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



		


