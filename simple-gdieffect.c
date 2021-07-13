#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#include <math.h>

long unsigned int UNFINITE = 10000000 * 25 * (68 && 10); // A simple replacement of INFINITE 

static unsigned long x = 123456789, y = 362436069, z = 521288629;

static long FastRnd( void )
{
	unsigned long t;
	x ^= x << 16;
	x ^= x << 5;
	x ^= x << 1;
	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;
	return z;
}

DWORD FirstPayload(

)
{
    clock_t click = clock();

    while ( ( clock() - click ) / CLOCKS_PER_SEC <= 15 )
    {
        HWND hwnd = GetDesktopWindow();
        HDC hdc = GetDC(hwnd);

        int width = GetSystemMetrics(SM_CXSCREEN);
        int height = GetSystemMetrics(SM_CYSCREEN);
        int colorVal = 255;

        HBRUSH brush = CreateSolidBrush(RGB(FastRnd() % colorVal, FastRnd() % colorVal, FastRnd() % colorVal));
    //    SelectObject(hdc, brush);
        // HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		int y = FastRnd() % width;
	    SelectObject(hdc, brush);
	    BitBlt(hdc, 0, y, width, 300, hdc, rand() % 61 - 30 >> 4, y ^ 3, SRCCOPY ^ 0x0101);
    }
}

DWORD SecondPayload(

)
{
    
    int rads = 180, s = (int) (3276 * sin(3 * 11 * rads) + 32767);
    clock_t load = clock();

    while ((clock() - load) / CLOCKS_PER_SEC <= 15)
    {
         RECT rekt;
        POINT pt[5];
        HWND hwnd = GetDesktopWindow();
        HDC hdc = GetDC(hwnd);
        GetWindowRect(hwnd, &rekt);

        int width = GetSystemMetrics(SM_CXSCREEN);
        int height = GetSystemMetrics(SM_CYSCREEN);

        pt[0].x = rekt.left + FastRnd() % 20;
		pt[0].y = rekt.top - FastRnd() % 20;
		pt[1].x = rekt.right + FastRnd() % 20;
		pt[1].y = rekt.top - FastRnd() % 20;
		pt[2].x = rekt.left + FastRnd() % 20;
		pt[2].y = rekt.bottom + FastRnd() % 20;
		pt[3].x = rekt.left + FastRnd() % 20;
		pt[3].y = rekt.top - FastRnd() % 20;
		pt[4].x = rekt.right - FastRnd() % 20;
		pt[4].y = rekt.top + FastRnd() % 20;
		pt[5].x = rekt.left - FastRnd() % 20;

        HBRUSH brush = CreateSolidBrush(RGB(FastRnd() % 255, FastRnd() % 255, FastRnd() % 255));
        SelectObject(hdc, brush);
		PatBlt(hdc, FastRnd() % s, FastRnd() % s, FastRnd() % width, FastRnd() % height, PATINVERT);
        PlgBlt(hdc, pt, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
    }
}

DWORD  ThirdPayload(
    
)
{
	int rads = 180;
	int s = (int)(3276*sin(3*11*rads)+32767);
    clock_t load = clock();

    while ((clock() - load) / CLOCKS_PER_SEC <= 100)
    {
        RECT rekt;
        POINT pt[5];
        HWND hwnd = GetDesktopWindow();
        HDC hdc = GetDC(hwnd);
        GetWindowRect(hwnd, &rekt);

        int width = GetSystemMetrics(SM_CXSCREEN);
        int height = GetSystemMetrics(SM_CYSCREEN);

        pt[0].x = rekt.left + FastRnd() % 20;
		pt[0].y = rekt.top - FastRnd() % 20;
		pt[1].x = rekt.right + FastRnd() % 20;
		pt[1].y = rekt.top - FastRnd() % 20;
		pt[2].x = rekt.left + FastRnd() % 20;
		pt[2].y = rekt.bottom + FastRnd() % 20;
		pt[3].x = rekt.left + FastRnd() % 20;
		pt[3].y = rekt.top - FastRnd() % 20;
		pt[4].x = rekt.right - FastRnd() % 20;
		pt[4].y = rekt.top + FastRnd() % 20;
		pt[5].x = rekt.left - FastRnd() % 20;

        HBRUSH brush = CreateSolidBrush(RGB(FastRnd() % 255, FastRnd() % 255, FastRnd() % 255));
        SelectObject(hdc, brush);
		BitBlt(hdc, rekt.left, rekt.top + FastRnd() % 1, rekt.right + 1, rekt.bottom + FastRnd() % 1, hdc, rekt.left + 1, rekt.top + FastRnd() % 1, SRCAND);
		BitBlt(hdc, rekt.left, rekt.top + 1, rekt.right, rekt.bottom + FastRnd() % 1, hdc, rekt.left, rekt.top - FastRnd() % 1, PATINVERT);
		
		PatBlt(hdc, FastRnd() % s, FastRnd() % s, FastRnd() % width, FastRnd() % height, PATINVERT);
        PlgBlt(hdc, pt, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		
    }
}

DWORD  SyncSound_1(

)
{
    clock_t load = clock();

    while ((clock() - load) / CLOCKS_PER_SEC <= 15)
    {
        HWAVEOUT hWaveOut;
        WAVEFORMATEX wfx;
        wfx.wFormatTag = WAVE_FORMAT_PCM;
        wfx.nChannels = 1;
        wfx.nSamplesPerSec = 24000;
        wfx.nAvgBytesPerSec = 24000;
        wfx.nBlockAlign = 1;
        wfx.wBitsPerSample = 8;
        wfx.cbSize = 0;

        waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
        char buffer[12000 * 60];

        for (DWORD t = 0; t < sizeof(buffer); t++)
        {
            buffer[t] = ((t * 10 * 100));
            // Over of integer handle value may give warning
        }

        WAVEHDR wHeader;
        wHeader.lpData = buffer;
        wHeader.dwBufferLength = sizeof(buffer);
        wHeader.dwBytesRecorded = 0;
        wHeader.dwUser = 0;
        wHeader.dwFlags = 0;
        wHeader.dwLoops = 0;
        wHeader.lpNext = 0;
        wHeader.reserved = 0;

        waveOutPrepareHeader(hWaveOut, &wHeader, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &wHeader, sizeof(WAVEHDR));
        waveOutUnprepareHeader(hWaveOut, &wHeader, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);
    }
}

DWORD  SyncSound_2(

)
{
    clock_t load = clock();

    while ((clock() - load) / CLOCKS_PER_SEC <= 15)
    {
        HWAVEOUT hWaveOut;
        WAVEFORMATEX wfx;
        wfx.wFormatTag = WAVE_FORMAT_PCM;
        wfx.nChannels = 1;
        wfx.nSamplesPerSec = 24000;
        wfx.nAvgBytesPerSec = 24000;
        wfx.nBlockAlign = 1;
        wfx.wBitsPerSample = 22;
        wfx.cbSize = 0;

        waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
        char buffer[12000 * 60];

        for (DWORD t = 0; t < sizeof(buffer); t++)
        {
            buffer[t] = ((t >> 10) & 100) * t;
            // Over of integer handle value may give warning
        }

        WAVEHDR wHeader;
        wHeader.lpData = buffer;
        wHeader.dwBufferLength = sizeof(buffer);
        wHeader.dwBytesRecorded = 0;
        wHeader.dwUser = 0;
        wHeader.dwFlags = 0;
        wHeader.dwLoops = 0;
        wHeader.lpNext = 0;
        wHeader.reserved = 0;

        waveOutPrepareHeader(hWaveOut, &wHeader, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &wHeader, sizeof(WAVEHDR));
        waveOutUnprepareHeader(hWaveOut, &wHeader, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);
    }
}

DWORD SyncSound_3(

)
{
     clock_t load = clock();

    while ((clock() - load) / CLOCKS_PER_SEC <= 100)
    {
        HWAVEOUT hWaveOut;
        WAVEFORMATEX wfx;
        wfx.wFormatTag = WAVE_FORMAT_PCM;
        wfx.nChannels = 1;
        wfx.nSamplesPerSec = 24000;
        wfx.nAvgBytesPerSec = 24000;
        wfx.nBlockAlign = 1;
        wfx.wBitsPerSample = 22;
        wfx.cbSize = 0;

        waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
        char buffer[12000 * 60];

        for (DWORD t = 0; t < sizeof(buffer); t++)
        {
            buffer[t] = ((t >> 1000) & 100200) * t;
            // Over of integer handle value may give warning
        }

        WAVEHDR wHeader;
        wHeader.lpData = buffer;
        wHeader.dwBufferLength = sizeof(buffer);
        wHeader.dwBytesRecorded = 0;
        wHeader.dwUser = 0;
        wHeader.dwFlags = 0;
        wHeader.dwLoops = 0;
        wHeader.lpNext = 0;
        wHeader.reserved = 0;

        waveOutPrepareHeader(hWaveOut, &wHeader, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &wHeader, sizeof(WAVEHDR));
        waveOutUnprepareHeader(hWaveOut, &wHeader, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);
    }
}

int main()
{
    // Threading may causes app crash, I'ld recommend create the thread more better rather this code.
    
    CreateThread(NULL, 0, FirstPayload, NULL, 0, NULL);
    CreateThread(NULL, 0, SyncSound_1, NULL, 0, NULL);
    Sleep(5000);

    CreateThread(NULL, 0, SecondPayload, NULL, 0, NULL);
    Sleep(5000);

    CreateThread(NULL, 0, ThirdPayload, NULL, 0, NULL);
    CreateThread(NULL, 0, SyncSound_3, NULL, 0, NULL);
    Sleep(5000);
    return 0;
}
