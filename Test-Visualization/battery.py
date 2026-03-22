import tkinter as tk

class BatteryDisplay:
    def __init__(self, root, width=200, height=100):
        self.canvas = tk.Canvas(root, width=width + 40, height=height + 40, bg='#2c3e50', highlightthickness=0)
        self.canvas.pack(padx=20, pady=20)
        
        self.w = width
        self.h = height
        self.x0, self.y0 = 20, 20
        
        self.canvas.create_rectangle(self.x0, self.y0, self.x0 + self.w, self.y0 + self.h, outline="#ecf0f1", width=4)
        self.canvas.create_rectangle(self.x0 + self.w, self.y0 + self.h//4, self.x0 + self.w + 10, self.y0 + 3*self.h//4, fill="#ecf0f1", outline="#ecf0f1")
        
        self.fill = self.canvas.create_rectangle(self.x0 + 5, self.y0 + 5, self.x0 + 5, self.y0 + self.h - 5, fill="#2ecc71", outline="")
        
        self.label = tk.Label(root, text="", font=("Arial", 14, "bold"), fg="white", bg="#2c3e50")
        self.label.pack()

    def update_battery(self, percentage):
        percentage = max(0, min(100, percentage))
        
        fill_width = (self.w - 10) * (percentage / 100)
        self.canvas.coords(self.fill, self.x0 + 5, self.y0 + 5, self.x0 + 5 + fill_width, self.y0 + self.h - 5)
        
        color = "#e74c3c" if percentage <= 20 else "#2ecc71"
        self.canvas.itemconfig(self.fill, fill=color)
        
        self.label.config(text=f"Battery: {percentage}%")

root = tk.Tk()
root.configure(bg='#2c3e50')
root.title("LoRaWAN Battery Monitor")

battery = BatteryDisplay(root)

test_battery_level = 75
battery.update_battery(test_battery_level)

root.mainloop()