import time
from zlaser import ZLaser

if __name__ == '__main__':

	LASER_OFF         = 0
	LASER_ON          = 1
	
	print('Initialize device...')
	p = ZLaser("\\\\.\\COM9")
	print(p)

	# print('Panel self-testing...', end='', flush=True)
	# p.test()
	# print('done')

	print('Measuring FLUO...',  end='', flush=True)
	p.set_led("FLUO", LED_RED_BLINK);
	time.sleep(5)
	p.set_led("FLUO", LED_GREEN);
	print('done')

	print('Measuring LWIR...',  end='', flush=True)
	p.set_led("LWIR", LED_RED_BLINK);
	time.sleep(5)
	p.set_led("LWIR", LED_GREEN);
	print('done')

	print('Measuring MWIR...',  end='', flush=True)
	p.set_led("MWIR", LED_RED_BLINK);
	time.sleep(5)
	p.set_led("MWIR", LED_GREEN);
	print('done')

	print('Measuring SWIR...',  end='', flush=True)
	p.set_led("SWIR", LED_RED_BLINK);
	time.sleep(5)
	p.set_led("SWIR", LED_GREEN);
	print('done')

	print('Measuring VNIR...',  end='', flush=True)
	p.set_led("VNIR", LED_RED_BLINK);
	time.sleep(5)
	p.set_led("VNIR", LED_GREEN);
	print('done')

	time.sleep(2)
	p.reset();


