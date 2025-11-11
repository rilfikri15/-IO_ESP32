# FreeRTOS TASK, RTOS SEM 5 Computer Engineering PENS

### Oleh: <br>
### Muhammad Alfarrel Arya Mahardika (3223600017)
###  Muhamad Beril Fikri Widjaya (3223600013)

<p> Pada repository ini berisikan program-program Task FreeRTOS yang menggunakan peripheral:<br>
<li> LED </li>
<li> Button
<li> Buzzer
<li> OLED
<li>Servo
<li> Stepper
<li> Encoder
<li> Potentiometer <br>
Masing-masing Peripheral akan di jalankan di prioritas yang sama dan core yang berbeda-beda </p>

Berikut Foto Rangkaian seluruh peripheral pada ESP-S3:<br>
![All peripheral](All%20peripheral/image_rtos.png) <br>

Jika anda ingin lebih lanjut mengetahui code dan video langkah-langkahnya, anda bisa mengunjungi folder 
[All Peripheral](https://github.com/MuhammadAlfarrel/-IO_ESP32/tree/main/All%20peripheral)<br>

<p>Tugas RTOS kali ini adalah mengimplementasi sistem operasi Real-Time Operating System (FreeRTOS) pada mikrokontroler ESP32-S3 untuk mendemonstrasikan kemampuan multitasking. FreeRTOS memungkinkan kita untuk membagi program besar menjadi unit-unit eksekusi yang lebih kecil dan independen yang disebut Task. Dengan FreeRTOS, kami dapat memastikan bahwa fungsi-fungsi real-time, seperti mengendalikan Servo, menggerakkan Stepper, dan membaca sensor, dapat berjalan secara bersamaan (konkuren) tanpa saling memblokir. Ini adalah peningkatan signifikan dibandingkan pemrograman bare-metal Arduino standar yang sering bergantung pada fungsi delay() yang memblokir semua operasi lain.</p>

<p>Untuk mencapai multitasking yang efisien, proyek ini membuat delapan (8) Task terpisah, di mana setiap task bertanggung jawab atas satu komponen perangkat keras spesifik (misalnya: OledTask, ServoTask, PotTask, dll.). Kami menggunakan fungsi xTaskCreatePinnedToCore() yang disediakan oleh ESP32 SDK untuk mengalokasikan setiap task ke salah satu dari dua inti pemrosesan (Core 0 atau Core 1) pada ESP32-S3. Distribusi task ke kedua inti ini memaksimalkan kinerja dan memanfaatkan arsitektur dual-core ESP32-S3 secara penuh, memungkinkan semua komponen beroperasi secara paralel.</p>

<p>Inti dari penggunaan FreeRTOS dalam kode ini terletak pada struktur loop tak terbatas (for (;;)) di dalam setiap fungsi Task dan pemanfaatan vTaskDelay(). Alih-alih mengunci sistem, vTaskDelay() berfungsi untuk menyerahkan kontrol kembali ke scheduler FreeRTOS setelah setiap iterasi, memastikan bahwa task lain mendapat kesempatan untuk dieksekusi. Ini menciptakan lingkungan non-blocking di mana OLED dapat diperbarui, Servo dapat bergerak, dan nilai Potensiometer dapat dibaca secara serentak, membuktikan kemampuan FreeRTOS dalam mengelola sumber daya dan waktu secara efektif.</p><br>

Berikut Hasil Program seluruh Task Peripheral di ESP32-S3 pada simulasi Wokwi:<br>
![Image](https://github.com/user-attachments/assets/ad752676-cab1-4c85-ba46-8475105fb4e1)
