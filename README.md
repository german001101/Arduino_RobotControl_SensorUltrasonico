# Arduino Robot Control Remoto

# Robot con Control Remote y sensor Ultrasonico

Robot con movimiento a base de un control remoto y Sensor Ultrasonico

# Componentes utilizados

- 2 Leds Rojos
- 2 Leds Blancos
- 2 Resistencias de 270 Ohms 1/2w (1 resistencia para cada led rojo para controla independientemente)
- 1 Resistencias de 270 Ohms 1/2w (para los 2 leds Blancos que se conectarán en paralelo) 
- Sensor ultrasonico
- Control Remoto(Se utiliza cualquier remoto, en mi caso utilizo un control Remoto de un Roku)
- 2 Motores (Motor Motorreductor)
- 2 Ruedas de Goma que iran a los motores
- Placa Arduino Uno

# Código utilizado del control remoto

0x57436699   <=(boton salir)
0x5743C03F   home

0x57439867 arriba
0x57439966 arriba/sostenido
0x57437887 izquierda
0x57437986 izquierda/sostenido
0x5743B44B derecha
0x5743B54A derecha/sostenido
0x5743CC33 abajo
0x5743CD32 abajo/sostenido
0x703748B    detener
0x574354AB detener
0x574355AA detener/sostenido


0x57431EE1 rebobinar
0x57438679 asterico
0x57432CD3 rebobinar atras
0x574332CD play/pause
0x5743AA55 rebobinar adelante

