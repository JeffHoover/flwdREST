from Adafruit_LED_Backpack import AlphaNum4

def test(message):
    # Create display instance on default I2C address (0x70) and bus number.
    display = AlphaNum4.AlphaNum4()

    # Alternatively, create a display with a specific I2C address and/or bus.
    # display = AlphaNum4.AlphaNum4(address=0x74, busnum=1)

    # Initialize the display. Must be called once before using the display.
    display.begin()

    # Clear the display buffer.
    display.clear()

    # Print first 4 characters of string to the display buffer.
    display.print_str(message[0:4].upper())

    # Write the display buffer to the hardware.
    # This must be called to update the actual display LEDs.
    display.write_display()

