import tkinter as tk
import math

class ValveDisplay:
    def __init__(self, root, size=400):
        self.canvas = tk.Canvas(root, width=size, height=size, bg='#2c3e50')
        self.canvas.pack(padx=20, pady=20)
        
        self.center = size // 2
        self.radius = size * 0.4
        
        self.canvas.create_oval(self.center - self.radius, self.center - self.radius,
                                 self.center + self.radius, self.center + self.radius, 
                                 outline="#ecf0f1", width=5)
        
        self.line = self.canvas.create_line(self.center, self.center, 
                                            self.center + self.radius, self.center, 
                                            fill="#e74c3c", width=8, capstyle="round")
        
        self.angle_label = tk.Label(root, text="", font=("Arial", 14), fg="white", bg="#2c3e50")
        self.angle_label.pack()
        
        self.percent_label = tk.Label(root, text="", font=("Arial", 14), fg="white", bg="#2c3e50")
        self.percent_label.pack(pady=10)

    def update_display(self, cos_val, sin_val):
        radians = math.atan2(sin_val, cos_val)
        degrees = math.degrees(radians)
        
        if degrees < 0:
            degrees += 360
            
        percent_open = (degrees / 360) * 100
        
        new_x = self.center + self.radius * cos_val
        new_y = self.center - self.radius * sin_val 
        
        self.canvas.coords(self.line, self.center, self.center, new_x, new_y)
        self.angle_label.config(text=f"Angle: {degrees:.1f}°")
        self.percent_label.config(text=f"Valve Open: {percent_open:.1f}%")

root = tk.Tk()
root.configure(bg='#2c3e50')
root.title("Static Valve Monitor")

# Change values here to test angles
static_cos = 1.0
static_sin = 0.0

valve = ValveDisplay(root)
valve.update_display(static_cos, static_sin)

root.mainloop()