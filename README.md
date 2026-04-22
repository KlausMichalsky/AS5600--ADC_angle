# AS5600_ADC-angle
### Lectura de ángulo analógico desde sensor AS5600 (salida OUT)
  - Lee directamente la salida analógica del AS5600 usando un pin ADC (GP26).
  - Convierte el valor leído (0–1023) en un ángulo equivalente entre 0° y 360°.
  - Muestra el ángulo por Serial cada 100 ms.
  - Método simple y rápido sin usar I2C ni librerías.
  - Ideal para pruebas rápidas o cuando solo se usa la salida OUT del AS5600.


# AS5600_I2C-angle
### Lectura de ángulo digital desde sensor AS5600 (salida I2C)
  - Lee el ángulo del sensor AS5600 conectado a GP26 (SDA) y GP27 (SCL) usando I2C.
  - Convierte el valor crudo de 12 bits (0–4095) a grados (0°–360°).
  - Muestra el ángulo por Serial cada 200 ms.
  - Usa Wire1 para I2C independiente de los pines por defecto.
