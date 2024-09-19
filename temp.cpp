fs = 10000;
fm = 100;
t = 0:1/fs:1000/fs;
x = 5 * sin(2 * pi * 100 * t);
figure;
subplot(2,1,1);
plot(t, x);
title('Signal')


y = [0];
xr = 0;
level = 0.4;


for i = 1:length(x) - 1
    if xr(i) <= x(i)
        d = 1;
        xr(i + 1) = xr(i) + level;
    else
        d = 0;
        xr(i + 1) = xr(i) - level;
    end
    y = [y d];
end
stairs(t, xr);
title('StairCase approximation signal')


MES = sum((x - xr).^2) / length(x);
figure;
%delta modulation
subplot(3,1,1)
plot(t, y);
title('Delta modulated signal')

%delta demodulation
subplot(3,1,2)
y_demod = [0];
xr_demod = 0;


for i = 2:length(y)
if y(i) == 1
    xr_demod = xr_demod + level;
else
    xr_demod = xr_demod - level;
end
    y_demod = [y_demod xr_demod];
end

plot(t, y_demod);
title('Delta demulated signal before filtering');


%applaying low pass filter
filter_oder = 20;
lowpass_filter = fir1(filter_oder, (fm*2)/(fs/2), 'low');
filter_demod_signal = filter(lowpass_filter, 1, y_demod);

subplot(3,1,3);
plot(t, filter_demod_signal);
title('Delta demodulated signal after filtering');








