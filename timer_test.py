import tkinter as tk
from tkinter import ttk
import time
import subprocess
#"C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\LowLevelBatt.png"
from PIL import Image

class App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.im = Image.open("C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\LowLevelBatt.png")
        print(self.im.mode)

        self.overrideredirect(True)
        self.config(bg="blue", bd=0, highlightthickness=0)
        self.attributes("-transparentcolor", "blue")


        self.canvas = tk.Canvas(self, bg="blue",width=1200,height=900, bd=0, highlightthickness=0)
        self.canvas.pack()

        self.tk_img = tk.PhotoImage(file="C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\LowLevelBatt.png")
        self.clean_img = tk.PhotoImage(file="C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\Clean.png")
        self.image_container = self.canvas.create_image(600, 300, image=self.tk_img, anchor="center")


        
        

        self.lift()
        self.attributes('-topmost',True)
        self.after_idle(self.attributes,'-topmost',False)
        self.after(1000,lambda:self.start())
        self.event_counter = 0
    def start(self):
  
        if (self.event_counter % 2) == 0:
            self.canvas.itemconfig(self.image_container,image=self.tk_img)
        else:
            self.canvas.itemconfig(self.image_container,image=self.clean_img)
        self.event_counter+=1
        if self.event_counter > 4:

            self.after(2000,lambda:self.destroy())
            
            subprocess.Popen("start C:\\NirCmd\\nircmd.exe monitor off", shell=True)
        else:
            self.after(1000,lambda:self.start())
        
    




if __name__ == "__main__":
    app = App()
    app.mainloop()