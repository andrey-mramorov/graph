from tkinter import *
import random
from math import sin, cos, pi
from tkinter.messagebox import *

root = Tk()
root.title("Fractal")

cvs = Canvas(root, height = 700, width = 1200, bg = 'white')
clr = Button(root, text = "Clear", width = 10, font = "Ubuntu, 20")
label1 = Label(root, text = "Len", width = 6, height = 2, font = "Ubuntu, 20", fg = "red", bg = "gray")
label2 = Label(root, text = "Order", width = 6, height = 2, font = "Ubuntu, 20", fg = "red", bg = "gray")
txt1 = Entry(root, width = 4,  font = "Ubuntu, 20")
txt2 = Entry(root, width = 4,  font = "Ubuntu, 20")

clr.grid(row = 2, column = 0, columnspan = 4, sticky = "ew")
cvs.grid(row = 1, column = 0, columnspan = 4, sticky = "ew")
label1.grid(row = 0, column = 0, sticky = W)
label2.grid(row = 0, column = 2, sticky = W)
txt1.grid(row = 0, column = 1, sticky = W)
txt2.grid(row = 0, column = 3, sticky = W)

txt1.insert(END, "3")
txt2.insert(END, "16")

def draw(event):
    try:
        x0 = event.x                     
        y0 = event.y
        a = 0
        
        d = int(txt1.get())
        n = int(txt2.get())
        
        r = random.randint(0, 255)
        g = random.randint(0, 255)
        b = random.randint(0, 255)
        hexstr = "#{:02x}{:02x}{:02x}".format(r, g, b)

        S = "1"
        for i in range (2, n + 1):
            t = len(S) // 2
            R = S[:t] + '0' + S[t + 1:]
            S = S + "1" + R
            
        for i in range (len(S)):

            if S[i] == "1":
                a = a + pi / 2
            else:
                a = a - pi / 2
                
            x = x0 + d * cos(a)
            y = y0 - d * sin(a)
            cvs.create_line(x0, y0, x, y, fill = hexstr, width = 1)
            x0, y0 = x, y                
                
    except:
        showerror("Error", "Enter lenght or order")
    
    
    
def Clear(event):
    cvs.delete("all")
    
cvs.bind("<Button-1>", draw)
clr.bind("<Button-1>", Clear)



root.mainloop()
