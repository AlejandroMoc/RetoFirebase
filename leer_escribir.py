'''
Python Firebase Course for
Beginners
https://codeloop.org/python-firebase-course-for-beginners/
'''
import pyrebase

config = {
"apiKey": "AIzaSyCkZtABLrWDkAvyqf8IRr5s3kIwp724vXo",
"authDomain": "corintios-5023e.firebaseapp.com",
"databaseURL": "https://corintios-5023e-default-rtdb.firebaseio.com/",
"projectId": "corintios-5023e",
"storageBucket": "corintios-5023e.appspot.com",
"messagingSenderId": "65486733713",
"appId": "1:65486733713:web:cbe0776a0cf8fadefbda30",
"measurementId": "G-SBB7DD27KG"
}

firebase = pyrebase.initialize_app(config)
#accesing database in firebase
db = firebase.database()

#reading some atributes of the onKey elements
all_users = db.child("app_inventor").get()
i = 0
for users in all_users.each():
    if (i == 4):
        break
    print(users.val())
    i = i + 1
num = int(users.val())
print("Valor de Número: ")
print(num)

#undating "usuario" data
if (num > 9):
    db.child("app_inventor").update({"Usuario":"Elemento mayor a 9"})
    print("Actualizado")
else:
    print("No Actualizado")
