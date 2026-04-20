#include <iostream>
using namespace std;

int main() {
    int n;
    float notas[20][4];
    float promedioEst, sumaGeneral = 0;
    float mayor = 0, menor = 100;
    int aprobados = 0, reprobados = 0;

    cout << "Cantidad de estudiantes (max 20): ";
    cin >> n;

    // Validación
    while (n < 1 || n > 20) {
        cout << "Error. Ingrese entre 1 y 20: ";
        cin >> n;
    }

    // Entrada de datos
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        for (int j = 0; j < 4; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> notas[i][j];

            while (notas[i][j] < 0 || notas[i][j] > 100) {
                cout << "Error. Nota entre 0 y 100: ";
                cin >> notas[i][j];
            }

            // Mayor y menor
            if (notas[i][j] > mayor) mayor = notas[i][j];
            if (notas[i][j] < menor) menor = notas[i][j];
        }
    }

    cout << "\n--- RESULTADOS ---\n";

    // Procesamiento
    for (int i = 0; i < n; i++) {
        float suma = 0;
        cout << "\nEstudiante " << i + 1 << ": ";

        for (int j = 0; j < 4; j++) {
            cout << notas[i][j] << " ";
            suma += notas[i][j];
        }

        promedioEst = suma / 4;
        cout << " | Promedio: " << promedioEst;

        sumaGeneral += promedioEst;

        if (promedioEst >= 70)
            aprobados++;
        else
            reprobados++;
    }

    float promedioGeneral = sumaGeneral / n;

    cout << "\n\nPromedio general: " << promedioGeneral;
    cout << "\nNota mayor: " << mayor;
    cout << "\nNota menor: " << menor;
    cout << "\nAprobados: " << aprobados;
    cout << "\nReprobados: " << reprobados;

    return 0;
}