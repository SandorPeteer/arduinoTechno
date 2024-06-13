volatile uint8_t poti = 0;  // Tárolja a potméter értékét
volatile uint8_t cycleCount = 0; // Ciklusszámláló
volatile float alpha = 1; // Smoothing factor (adjust as needed)
volatile float filteredValue = 0;

void setup() {
  // Set the reference voltage to 1.1V (internal)
  ADMUX = (1 << REFS1) | (1 << REFS0) | (1 << ADLAR);

  // Select the ADC channel (A0)
  ADMUX |= (0 << MUX0);

  // Set ADC prescaler to 16 for a 1 MHz ADC clock
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS0);

  // Enable ADC interrupt
  ADCSRA |= (1 << ADIE);

  // Start the first conversion
  ADCSRA |= (1 << ADSC);

  // Configure PORTD as output
  DDRD = 0xFF;

  // Enable global interrupts
  sei();
}

ISR(ADC_vect) {
  // Read the 8-bit result from ADCH register
  uint8_t adcValue = ADCH;

  // Check cycle count to decide which channel to read
  cycleCount++;
  if (cycleCount >= 254) {
    // Read potentiometer value from A1 every 128 cycles
    ADMUX = (ADMUX & 0xF0) | (1 << MUX0); // Select A1
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC)); // Wait for conversion to complete
    poti = ADCH; // Store potentiometer value
    cycleCount = 0;
    ADMUX = (ADMUX & 0xF0); // Re-select A0
    alpha = (poti + 5) * 0.00392;
  }

  // Output the audio input result to PORTD

  filteredValue = alpha * adcValue + (1 - alpha) * filteredValue;

  PORTD = filteredValue;
  // Start the next conversion
  ADCSRA |= (1 << ADSC);
}

void loop() {
  // The main loop does nothing, all work is done in ISR
}
