from telegram import Update
from telegram.ext import Application, CommandHandler, MessageHandler, filters
from PIL import Image, ImageFilter, ImageEnhance
from pydub import AudioSegment
import os

# Функція для стартової команди /start
async def start(update: Update, context):
    await update.message.reply_text(
        "Вітаю! Надішліть мені фотографію, звукове повідомлення або MP3 файл."
    )

# Обробник фотографій
async def handle_photo(update: Update, context):
    # Завантажуємо фотографію
    photo_file = await update.message.photo[-1].get_file()
    photo_path = 'received_photo.jpg'
    await photo_file.download_to_drive(photo_path)
    context.user_data['photo_path'] = photo_path
    context.user_data['file_type'] = 'photo'

    await update.message.reply_text(
        "Фотографія отримана. Тепер введіть команди для редагування (наприклад: /зменшити, /розмити, /контраст, /обернути)."
    )

# Обробник звукових повідомлень
async def handle_voice(update: Update, context):
    # Завантажуємо звукове повідомлення
    voice_file = await update.message.voice.get_file()
    voice_path = 'received_voice.ogg'
    await voice_file.download_to_drive(voice_path)
    context.user_data['audio_path'] = voice_path
    context.user_data['file_type'] = 'voice'

    await update.message.reply_text(
        "Звукове повідомлення отримане. Тепер введіть команди для редагування (наприклад: /сповільнити, /прискорити, /низький тон, /високий тон)."
    )

# Обробник MP3 файлів
async def handle_audio(update: Update, context):
    # Завантажуємо аудіофайл
    audio_file = await update.message.audio.get_file()
    audio_path = 'received_audio.mp3'
    await audio_file.download_to_drive(audio_path)
    context.user_data['audio_path'] = audio_path
    context.user_data['file_type'] = 'audio'

    await update.message.reply_text(
        "MP3 файл отриманий. Тепер введіть команди для редагування (наприклад: /сповільнити, /прискорити, /низький тон, /високий тон)."
    )

# Обробник текстових команд для редагування
async def handle_text(update: Update, context):
    if 'file_type' not in context.user_data:
        await update.message.reply_text("Будь ласка, спочатку надішліть фото, звукове повідомлення або MP3 файл.")
        return

    commands = [cmd.strip().lower() for cmd in update.message.text.split(',')]
    file_type = context.user_data['file_type']

    if file_type == 'photo':
        photo_path = context.user_data['photo_path']
        with Image.open(photo_path) as img:
            applied_actions = []

            for command in commands:
                if 'зменшити' in command:
                    img = img.resize((300, 300))
                    applied_actions.append("Фото зменшено.")
                elif 'розмити' in command:
                    img = img.filter(ImageFilter.BLUR)
                    applied_actions.append("Фото розмито.")
                elif 'контраст' in command:
                    enhancer = ImageEnhance.Contrast(img)
                    img = enhancer.enhance(2.0)  # Збільшення контрасту
                    applied_actions.append("Контраст збільшено.")
                elif 'обернути' in command:
                    img = img.rotate(90)  # Обертання на 90 градусів
                    applied_actions.append("Фото обернуто.")
                else:
                    applied_actions.append(f"Команда '{command}' не розпізнана.")

            # Зберігаємо відредаговане зображення
            edited_photo_path = 'edited_photo.jpg'
            img.save(edited_photo_path)
            await update.message.reply_photo(photo=open(edited_photo_path, 'rb'))
            await update.message.reply_text(" ".join(applied_actions))

    elif file_type in ['voice', 'audio']:
        audio_path = context.user_data['audio_path']
        audio_format = 'ogg' if file_type == 'voice' else 'mp3'
        audio = AudioSegment.from_file(audio_path, format=audio_format)
        applied_actions = []

        for command in commands:
            if 'сповільнити' in command:
                if audio.frame_rate != 0:  # Перевірка frame_rate звуку
                    # Зниження швидкості (сповільнення) за рахунок зниження частоти дискретизації
                    new_sample_rate = int(audio.frame_rate * 0.5)  # Зменшуємо частоту дискретизації вдвічі
                    audio = audio._spawn(audio.raw_data, overrides={'frame_rate': new_sample_rate})
                    audio = audio.set_frame_rate(audio.frame_rate)
                    applied_actions.append("Звук сповільнено.")
                else:
                    applied_actions.append("Не вдалося сповільнити звук (frame_rate дорівнює нулю).")
            elif 'прискорити' in command:
                if audio.frame_rate != 0: 
                    # Збільшення швидкості (прискорення) за рахунок збільшення частоти дискретизації
                    new_sample_rate = int(audio.frame_rate * 1.5)  # Збільшуємо частоту дискретизації в 1.5 рази
                    audio = audio._spawn(audio.raw_data, overrides={'frame_rate': new_sample_rate})
                    audio = audio.set_frame_rate(audio.frame_rate)
                    applied_actions.append("Звук прискорено.")
                else:
                    applied_actions.append("Не вдалося прискорити звук (frame_rate дорівнює нулю).")
            elif 'низький тон' in command:
                if audio.frame_rate != 0: 
                    new_sample_rate = max(int(audio.frame_rate / 1.2), 1)
                    audio = audio._spawn(audio.raw_data, overrides={'frame_rate': new_sample_rate})
                    audio = audio.set_frame_rate(audio.frame_rate)
                    applied_actions.append("Тон звуку знижено.")
                else:
                    applied_actions.append("Не вдалося змінити тон звуку (frame_rate дорівнює нулю).")
            elif 'високий тон' in command:
                if audio.frame_rate != 0: 
                    new_sample_rate = int(audio.frame_rate * 1.2)
                    audio = audio._spawn(audio.raw_data, overrides={'frame_rate': new_sample_rate})
                    audio = audio.set_frame_rate(audio.frame_rate)
                    applied_actions.append("Тон звуку підвищено.")
                else:
                    applied_actions.append("Не вдалося змінити тон звуку (frame_rate дорівнює нулю).")
            else:
                applied_actions.append(f"Команда '{command}' не розпізнана.")

        # Зберігаємо відредагований звук
        edited_voice_path = 'edited_audio.ogg' if file_type == 'voice' else 'edited_audio.mp3'
        audio.export(edited_voice_path, format="ogg" if file_type == 'voice' else "mp3")
        await update.message.reply_voice(voice=open(edited_voice_path, 'rb')) if file_type == 'voice' else await update.message.reply_audio(audio=open(edited_voice_path, 'rb'))
        await update.message.reply_text(" ".join(applied_actions))

    # Скидаємо збережені дані після редагування
    context.user_data.clear()

# Основна функція для запуску бота
def main():
    application = Application.builder().token("").build()

    # Додаємо обробники
    application.add_handler(CommandHandler("start", start))
    application.add_handler(MessageHandler(filters.PHOTO, handle_photo))
    application.add_handler(MessageHandler(filters.VOICE, handle_voice))
    application.add_handler(MessageHandler(filters.AUDIO, handle_audio))
    application.add_handler(MessageHandler(filters.TEXT, handle_text))

    application.run_polling()

main()
