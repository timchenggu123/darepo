clc, clear
if 0
    %Q3

    h = 8;
    w = 500;
    L = 1500;
    V = h*w*L;
    Q = 1.5*10^5;
    kc = 0.10;
    Cin = 750 * 10^-3;
    A = h*w;
    v = Q/A;
    
    %a)
    syms C Css
    
    eqnss = 0 == Q*Cin - Q*Css -kc*Css*V;
    
    Css = double(solve(eqnss,Css))
    
   %b)
   
   Csses = [];
   V = V/5;
   V_a = 0; %start of CSTR
   V_b = 0; %end of CSTR
   Vs = [];
   
   Css = Cin;
   for i = 1:5
       Cin = Css;
       eqn =0 == Q*Cin - Q*C - kc*C*V;
       Css = double(solve(eqn,C));
       Csses = [Csses,Css,Css]; 
       V_b = V_a + V;
       Vs = [Vs,V_a,V_b];
       V_a = V_b;
   end
   
   %plot(Vs, Csses, '-k')
   
   %c)
   
   Cin = 750 * 10^-3
   
   syms eqn x
   
   eqn = exp(-kc/v*x) * Cin
   
   xPlot = linspace(1,L);
   CssPlot = subs(eqn,x,xPlot);
   
   xPlot1 = Vs/A;
   
   hold on 
   plot(xPlot,CssPlot,'-k')
   plot(xPlot1,Csses,'--b')
   hold off
   
   title('ENVE225A5-3 C vs x')
   xlabel('x (m)')
   ylabel('C(x) (\mug/m^3)')
   legend('1-D River','5 CSTRs')
end

if 0
    %225 A5-4
    clc, clear
    h = 8;
    w = 500;
    L = 1500;
    V = h*w*L;
    Q = 1.5*10^5;
    kc = 0.10;
    Cin = 750 * 10^-3;
    A = h*w;
    v = Q/A;
    
    Cin2 = 1200000;
    Qin2 = 1*10^-3*86400
    %a)
    syms C Css
    
    eqnss = 0 == Q*Cin - Q*Css -kc*Css*V;
    
    Css = double(solve(eqnss,Css));
    
   %b)
   
   Csses = [];
   V = V/5;
   L_a = 0; %start of CSTR
   L_b = 0; %end of CSTR
   xPlot1 = [];
   
   Css = Cin; %we are setting the initial concentration here
   for i = 1:5
       L_b = L_a + L/5;
       xPlot1 = [xPlot1,L_a,L_b];
       L_a = L_b;
       
       Cin = Css;
       if i == 3
        eqn =0 == Q*Cin - Q*C - kc*C*V + (Qin2*Cin2 - Qin2*C) ;
       elseif i > 3
        eqn =0 == (Q+Qin2)*Cin - (Q+Qin2)*C - kc*C*V; %CSTRS past the point source needs to take into account the point source flow
       else
        eqn =0 == Q*Cin - Q*C - kc*C*V;
       end
       Css = double(solve(eqn,C));
       Csses = [Csses,Css,Css]; 
   end
   
   %plot(Vs, Csses, '-k')
   
   %c)
   
   Cin = 750 * 10^-3
   
   syms eqn x
   
   eqn = (1-heaviside(x-L/2))* exp(-kc/v*x) * Cin + heaviside(x - L/2)*exp(-kc/((Q + Qin2)/A)*(x-L/2))*((exp(-kc/v*(L/2)) * Cin + Cin2*Qin2/(Qin2 + Q)));
   
   xPlot = linspace(0,L);
   CssPlot = subs(eqn,x,xPlot);
   
   
   hold on 
   plot(xPlot,CssPlot,'-k')
   plot(xPlot1,Csses,'--b')
   hold off
   
   title('ENVE225A5-3 C vs x')
   xlabel('x (m)')
   ylabel('C(x) (\mug/m^3)')
   legend('1-D River','5 CSTRs')
end

if 0
    %A5 -5
    Q1 = 12*10^6;
    C1 = 1;
    Q2 = 5*10^5;
    C2 = 400;
    A1 = 2000;
    A2 = 3000;
    k = 0.8;
    w = 30000;
    x1 = 8*1000;
    x2 = 16*1000;
    syms Css x W A v
    
    Q = Q1 + Q2;
    C = (Q1*C1 + Q2*C2)/Q;
    
    A = (1-heaviside(x-x1))*2000 + heaviside(x-1)*3000;
    v = Q/A;
    W = heaviside(x-x1)*w/k/A*(1 - exp(-k/v*(x-x1)))...
        - heaviside(x-x2)*w/k/A*(1 - exp(-k/v*(x-x2)));
    Css = C*exp(-k/v*x) ...
        + W 
    xPlot = linspace(0,24000);
    CssPlot = subs(Css,x,xPlot);
    plot(xPlot,CssPlot,'-k')
    
end    