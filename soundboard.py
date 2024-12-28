import pygame
from pygame.locals import K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, K_9

# Initialize pygame mixer and window
pygame.init()
pygame.mixer.init()

# Load sounds for keys 1-9
sounds = {
    K_1: pygame.mixer.Sound('sound1.wav'),
    K_2: pygame.mixer.Sound('sound2.wav'),
    K_3: pygame.mixer.Sound('sound3.wav'),
    K_4: pygame.mixer.Sound('sound4.wav'),
    K_5: pygame.mixer.Sound('sound5.wav'),
    K_6: pygame.mixer.Sound('sound6.wav'),
    K_7: pygame.mixer.Sound('sound7.wav'),
    K_8: pygame.mixer.Sound('sound8.wav'),
    K_9: pygame.mixer.Sound('sound9.wav'),
}

# Main loop
running = True
screen = pygame.display.set_mode((200, 200))
pygame.display.set_caption("Soundboard")

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN and event.key in sounds:
            sounds[event.key].play()

pygame.quit()
