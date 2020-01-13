f = load('result.txt');

x = (0:length(f) - 1);
y = (0:length(f) - 1);
imagesc(x, y, f);
% stem3(x,y,f,'.');
colormap('jet');
colorbar;