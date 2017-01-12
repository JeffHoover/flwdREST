import time

from Adafruit_LED_Backpack import AlphaNum4

def test():
    # Create display instance on default I2C address (0x70) and bus number.
    display = AlphaNum4.AlphaNum4()

    # Alternatively, create a display with a specific I2C address and/or bus.
    # display = AlphaNum4.AlphaNum4(address=0x74, busnum=1)

    # Initialize the display. Must be called once before using the display.
    display.begin()

    # Scroll a message across the display
    message = 'FLWD CATS READ FAST FISH <-->'
    pos = 0
    print 'Press Ctrl-C to quit.'
    while True:
  	# Clear the display buffer.
	display.clear()
	# Print a 4 character string to the display buffer.
	display.print_str(message[pos:pos+4])
	# Write the display buffer to the hardware.  This must be called to
	# update the actual display LEDs.
	display.write_display()
	# Increment position. Wrap back to 0 when the end is reached.
	pos += 1
	if pos > len(message)-4:
		pos = 0
	# Delay for half a second.
	time.sleep(0.5)

# Note that the alphanumeric display has the same number printing functions
# as the 7 segment display.  See the sevensegment_test.py example for good
# examples of these functions.
