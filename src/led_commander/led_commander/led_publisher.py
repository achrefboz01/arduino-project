import rclpy
from rclpy.node import Node
import paho.mqtt.client as mqtt
import threading

class LEDPublisher(Node):
    def __init__(self):
        super().__init__('led_publisher')
        self.mqtt_client = mqtt.Client()
        self.mqtt_client.connect("192.168.137.142", 1883)  # IP de ton Pi

        # Démarrer un thread pour écouter l'entrée clavier sans bloquer ROS
        thread = threading.Thread(target=self.keyboard_input)
        thread.daemon = True
        thread.start()

    def keyboard_input(self):
        while True:
            cmd = input("Tape 'on' ou 'off' pour la LED (Ctrl+C pour quitter) : ")
            self.get_logger().info(f'Commande reçue: {cmd}')
            self.mqtt_client.publish("led/control", cmd)

def main(args=None):
    rclpy.init(args=args)
    node = LEDPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

