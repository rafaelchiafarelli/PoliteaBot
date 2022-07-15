#"C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\LowLevelBatt.png"
import tkinter as tk

from PIL import Image
im = Image.open("C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\LowLevelBatt.png")
print(im.mode)

root = tk.Tk()
root.overrideredirect(True)
root.config(bg="blue", bd=0, highlightthickness=0)
root.attributes("-transparentcolor", "blue")
root.lift()
root.attributes('-topmost',True)
root.after_idle(root.attributes,'-topmost',False)

canvas = tk.Canvas(root, bg="blue",width=1200,height=900, bd=0, highlightthickness=0)
canvas.pack()

tk_img = tk.PhotoImage(file="C:\\Users\\rafae\\Documents\\workspace\\PoliteaBot\\LowLevelBatt.png")
canvas.create_image(600, 300, image=tk_img, anchor="center")

root.after(3000,lambda:root.destroy())

root.mainloop()

