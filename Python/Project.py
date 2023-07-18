
# armyDetails
import mysql.connector
cnx=mysql.connector.connect(host='localhost',user='root',password='pass')
cursor=cnx.cursor()

pass_login=0

try:
    cnx=mysql.connector.connect(user='root',password='pass',host='localhost', port='3306', database='armyDetails')
except:
    cursor.execute("CREATE DATABASE army" )
    cnx=mysql.connector.connect(user='root',password='pass',host='localhost', port='3306', database='armyDetails')

def login():
    pas='312'
    global pass_login
    while pass_login==0:
        paswd=input('Enter password: ')
        if paswd==pas:
            #login confirmed
            pass_login+=1
        else:
            quit()
        

def menu():
    c='y'
    while (c=='y'):
        login()
        print('Enter 1 for officers record')
        print('Enter 2 for new candidates')
        ch=input('Enter your choice: ')
        print ("1. Add Record")
        print ("2. Update Record")
        print ("3. Delete Record")
        print ("4. Display Records")
        print ("5. Exiting")
        choice = int(input('Enter your choice: '))
        if choice == 1:
            if ch =='1':
                insertdata1()
            else:
                insertdata2()
        elif choice == 2:
            if ch == '1':
                updatedata1()
            else:
                updatedata2()
        elif choice == 3:
            if ch == '1':
                deletedata1()
            else:
                deletedata2()
        elif choice == 4:
            if ch == '1':
                show1()
            else:
                search2()
        elif choice == 5:
            print('Exiting...')
            quit()
        print('Do you want to proceed ')
        c=input('Enter "Y" to proceed: ').lower()
        
def insertdata1():
    global cursor
    cursor=cnx.cursor()
    o_id=int(input('ENTER CADET ID: '))
    o_name=input('ENTER ARMY OFFICER NAME: ')
    o_address=input('ENTER CITY NAME: ')[0:3]
    o_salary=int(input('ENTER SALARY: '))
    o_post=input('ENTER POST: ')
    qry=("INSERT INTO officersDetails VALUES(%s,%s,%s,%s,%s)")
    data=(o_id,o_name,o_address,o_salary,o_post)
    try:
        cursor.execute(qry,data)
    except:
        cursor.execute('CREATE TABLE officersDetails (oID INTEGER PRIMARY KEY,oName VARCHAR(25),oCName CHAR(3),oSal INTEGER,oPost VARCHAR(25));')
        cursor.execute(qry,data)
    
def deletedata1():
    global cursor
    cursor=cnx.cursor()
    oID=input('Enter the officers ID whose data is to be deleted: ')
    qry="DELETE FROM officersDetails WHERE oID= "+oID
    cursor.execute(qry)


def updatedata1():
    global cursor
    cursor=cnx.cursor(buffered=True)
    oID=input('Enter officers ID whose data is to updated: ')
    qry=('SELECT * FROM officersDetails WHERE oID=%s;')
    data=(oID,)
    
    cursor.execute(qry,data)
    print('ENTER NEW DATA')
    o_name=input('ENTER ARMY OFFICER NAME: ')
    o_post=input('ENTER POST: ')
    o_cname=input('ENTER CITY NAME: ')[0:3]
    o_salary=input('ENTER SALARY: ')
    qry=('UPDATE officersDetails SET oName= %s, oPost=%s, oCName=%s ,oSal=%s WHERE oID= %s ;')
    data=(o_name,o_post,o_cname,o_salary,oID)
    cursor.execute(qry,data)



def show1():
    global cursor
    cursor=cnx.cursor()
    qry=("SELECT * FROM officersDetails ;")
    try:
        cursor.execute(qry)
    except:
        print('Sorry something went wrong...')
    rec_count=0
    for (o_id,o_name,o_city,o_salary,o_post) in cursor:
        rec_count+=1
        print("============================================")
        print('OFFICER ID :', o_id)
        print('ARMY OFFICER NAME:', o_name)
        print('OFFICER POST :', o_post)
        print('ARMY OFFICER ADDRESS :',o_city)
        print('OFFICER SALARY :', o_salary)
        print("===========================================")


#-----------------------------------------------------------------------------------------------------------------------------------

# SOLDIER details

def insertdata2():
    global cursor
    cursor=cnx.cursor()
    cID=int(input('ENTER CANDIDATE ID: '))
    cName=input('ENTER CANDIDATE NAME: ')
    cCity=input('ENTER CANDIDATE CITY NAME: ')[0:3]
    qry=("INSERT INTO candidateDetails VALUES(%s,%s,%s) ;")
    data=(cID,cName,cCity)
    try:
        cursor.execute(qry,data)
    except:
        cursor.execute('CREATE TABLE candidateDetails (cID INTEGER PRIMARY KEY,cName VARCHAR(25),cCity CHAR(3));')
        cursor.execute(qry,data)
    
def deletedata2():
    global cursor
    cursor=cnx.cursor()
    cID=int(input('Enter CANDIDATE ID whose data is to be deleted: '))
    qry=("DELETE FROM candidateDetails WHERE cID=%s ;")
    delRecord=(cID,)
    try:
        cursor.execute(qry,delRecord)
    except:
        print('Something went wrong, data wasn\'t deleted...')


def updatedata2():
    global cursor
    cursor=cnx.cursor(buffered=True)
    cID=int(input("Enter CANDIDATE ID whose data is to be updated: "))
    qry=('SELECT * FROM candidateDetails WHERE cID=%s ;')
    prevData=(cID,)
    try:
        cursor.execute(qry,prevData)
    except:
        print('Sorry no directory found matching with details you entered!!!')
        return()
    print('ENTER NEW DATA')
    cName=input('ENTER CANDIDATE NAME: ')
    cCity=input('ENTER CANDIDATE CITY NAME: ')[0:3]
    qry=('UPDATE candidateDetails SET cName=%s ,cCity=%s WHERE cID=%s ;')
    data = (cName,cCity,cID)
    cursor.execute(qry,data)


def search2():
    global cursor
    cursor=cnx.cursor(buffered=True)
    qry=("SELECT * FROM candidateDetails")
    try:
        cursor.execute(qry)
        rec_count=0
        for (cID,cName,cCity) in cursor:
            rec_count+=1
            print("============================================")
            print()
            print('CANDIDATE ID: ', cID)
            print('CANDIDATE NAME: ',cName)
            print('CANDIDATE CITY: ',cCity)
            print()
            print("============================================")
    except:
        print('Sorry but no such directory found!!!')
    


    
    
    
menu()
