import random
import subprocess

def generate_random_password(length=8):
    return ''.join(random.choices('0123456789', k=length))

def connect_to_wifi(ssid, password):
    try:
        # Disconnect any existing connections
        subprocess.run(['nmcli', 'device', 'disconnect', 'wlan0'], check=True)
        
        # Remove any existing connection with the same name
        subprocess.run(['nmcli', 'connection', 'delete', ssid], check=True)
        
        # Try to connect to the specified WiFi network
        result = subprocess.run(['nmcli', 'device', 'wifi', 'connect', ssid, 'password', password], check=True, capture_output=True, text=True)
        
        if 'successfully' in result.stdout:
            print(f"Successfully connected to {ssid} with password {password}")
        else:
            print(f"Failed to connect to {ssid} with password {password}")
    except subprocess.CalledProcessError as e:
        print(f"Error connecting to WiFi: {e}")
        print(e.output)

def main():
    ssid = '`No Internet`'  # Replace with your WiFi SSID
    password = generate_random_password()
    print(f"Generated Password: {password}")
    connect_to_wifi(ssid, password)

if __name__ == '__main__':
    main()
