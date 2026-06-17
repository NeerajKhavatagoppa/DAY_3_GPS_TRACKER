import paho.mqtt.client as mqtt
import webbrowser

def on_message(client, userdata, msg):
    data = msg.payload.decode()
    print("Received:", data)
    
    lat, lon = data.split(",")
    
    # Set a zoom level, for example, 12 (more zoomed out)
    zoom = 12
    
    url = f"https://www.google.com/maps?q={lat},{lon}&z={zoom}"
    print("Opening:", url)
    webbrowser.open(url)

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1)

client.on_message = on_message

client.connect("localhost", 1883, 60)

client.subscribe("vehicle/location")

print("Waiting for location...")

client.loop_forever()