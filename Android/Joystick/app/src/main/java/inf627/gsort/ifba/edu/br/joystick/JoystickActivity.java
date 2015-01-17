package inf627.gsort.ifba.edu.br.joystick;

import android.app.Activity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageView;

public class JoystickActivity extends Activity {

    JoystickButtons joystickButtons;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        View decorView = getWindow().getDecorView();
        int uiOptions = View.SYSTEM_UI_FLAG_HIDE_NAVIGATION | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY;
        decorView.setSystemUiVisibility(uiOptions);

        setContentView(R.layout.joystick);

        final ImageView imageView = (ImageView) findViewById(R.id.joystickView);

        this.joystickButtons = new JoystickButtons();

        imageView.setOnTouchListener(new View.OnTouchListener() {

            float x, y;

            int action;
            int pointerIndex;
            int fingerId;

            boolean frente;
            boolean re;
            boolean esquerda;
            boolean direita;

            @Override
            public boolean onTouch(View v, MotionEvent event) {

                action = event.getAction() & MotionEvent.ACTION_MASK;
                pointerIndex = (event.getAction() & MotionEvent.ACTION_POINTER_INDEX_MASK) >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;
                fingerId = event.getPointerId(pointerIndex);

                if (event.getAction() == MotionEvent.ACTION_MOVE) {

                    frente = false;
                    re = false;
                    esquerda = false;
                    direita = false;

                    int pointerCount = event.getPointerCount();

                    for (int i = 0; i < pointerCount; i++) {
                        x = event.getX(i);
                        y = event.getY(i);

                        if (!frente) frente = verificaAreaFrente(x, y);
                        if (!re) re = verificaAreaRe(x, y);
                        if (!esquerda) esquerda = verificaAreaEsquerda(x, y);
                        if (!direita) direita = verificaAreaDireita(x, y);
                    }

                    if (frente) joystickButtons.startFrente();
                    else joystickButtons.stopFrente();

                    if (re) joystickButtons.startRe();
                    else joystickButtons.stopRe();

                    if (esquerda) joystickButtons.startEsquerda();
                    else joystickButtons.stopEsquerda();

                    if (direita) joystickButtons.startDireita();
                    else joystickButtons.stopDireita();
                }

                x = event.getX(pointerIndex);
                y = event.getY(pointerIndex);

                if (event.getAction() == MotionEvent.ACTION_DOWN || event.getAction() == MotionEvent.ACTION_POINTER_DOWN) {
                    if (verificaAreaFrente(x, y)) {
                        joystickButtons.startFrente();
                    }
                    if (verificaAreaRe(x, y)) {
                        joystickButtons.startRe();
                    }
                    if (verificaAreaEsquerda(x, y)) {
                        joystickButtons.startEsquerda();
                    }
                    if (verificaAreaDireita(x, y)) {
                        joystickButtons.startDireita();
                    }
                }
                if (event.getAction() == MotionEvent.ACTION_UP || event.getAction() == MotionEvent.ACTION_POINTER_UP) {
                    if (verificaAreaFrente(x, y)) {
                        joystickButtons.stopFrente();
                    }
                    if (verificaAreaRe(x, y)) {
                        joystickButtons.stopRe();
                    }
                    if (verificaAreaEsquerda(x, y)) {
                        joystickButtons.stopEsquerda();
                    }
                    if (verificaAreaDireita(x, y)) {
                        joystickButtons.stopDireita();
                    }
                }

                return true;
            }

            private boolean verificaAreaFrente(float x, float y) {
                return 225 < x && x < 515 && 170 < y && y < 420;
            }
            private boolean verificaAreaRe(float x, float y) {
                return 225 < x && x < 515 && 620 < y && y < 870;
            }
            private boolean verificaAreaEsquerda(float x, float y) {
                return 1000 < x && x < 1300 && 380 < y && y < 650;
            }
            private boolean verificaAreaDireita(float x, float y) {
                return 1500 < x && x < 1800 && 380 < y && y < 650;
            }

        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        Runnable r = new Runnable() {
            @Override
            public void run() {
                joystickButtons.init();
            }
        };

        Thread t = new Thread(r);
        t.start();
    };

    @Override
    protected void onPause() {
        super.onPause();
        Runnable r = new Runnable() {
            @Override
            public void run() {
                joystickButtons.destroy();
            }
        };

        Thread t = new Thread(r);
        t.start();
    }
}

