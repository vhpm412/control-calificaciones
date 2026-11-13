#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    char otroGrupo;

    // BUCLE do-while: repite todo el programa mientras el usuario responda 's'.
    do {
        int cantidadEstudiantes;
        int aprobados = 0;
        int reprobados = 0;
        double sumaPromedios = 0;
        double mejorPromedio = -1;
        string mejorEstudiante = "";

        cout << "Cantidad de estudiantes: ";
        cin >> cantidadEstudiantes;

        // BUCLE while: vuelve a pedir la cantidad mientras sea invalida (0 o menor).
        while (cin.fail() || cantidadEstudiantes <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Valor invalido. Debe ser un numero mayor que 0." << endl;
            cout << "Cantidad de estudiantes: ";
            cin >> cantidadEstudiantes;
        }

        // BUCLE for: recorre cada estudiante del grupo.
        for (int i = 1; i <= cantidadEstudiantes; i++) {
            string nombre;
            double nota;
            double sumaNotas = 0;

            cout << "\n--- Estudiante " << i << " ---" << endl;
            cout << "Nombre: ";
            cin >> nombre;

            // BUCLE for: recorre las 4 calificaciones de cada estudiante.
            for (int j = 1; j <= 4; j++) {
                cout << "Calificacion " << j << ": ";
                cin >> nota;

                // BUCLE while: repite la calificacion mientras este fuera del rango 0-100.
                while (cin.fail() || nota < 0 || nota > 100) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Calificacion invalida. Debe estar entre 0 y 100." << endl;
                    cout << "Calificacion " << j << ": ";
                    cin >> nota;
                }

                sumaNotas = sumaNotas + nota;
            }

            double promedio = sumaNotas / 4;
            sumaPromedios = sumaPromedios + promedio;

            cout << fixed << setprecision(2);
            cout << "Promedio: " << promedio << " - ";

            if (promedio >= 70) {
                cout << "Aprobado" << endl;
                aprobados++;
            } else {
                cout << "Reprobado" << endl;
                reprobados++;
            }

            if (promedio > mejorPromedio) {
                mejorPromedio = promedio;
                mejorEstudiante = nombre;
            }
        }

        double promedioGrupo = sumaPromedios / cantidadEstudiantes;

        cout << "\n===== RESUMEN =====" << endl;
        cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << endl;
        cout << "Promedio del grupo: " << promedioGrupo << endl;
        cout << "Mejor promedio: " << mejorEstudiante << " (" << mejorPromedio << ")" << endl;

        cout << "\nDesea procesar otro grupo? (s/n): ";
        cin >> otroGrupo;

        // BUCLE while: repite la pregunta mientras la respuesta no sea s o n.
        while (otroGrupo != 's' && otroGrupo != 'n') {
            cout << "Respuesta invalida. Escriba s o n: ";
            cin >> otroGrupo;
        }

        cout << endl;

    } while (otroGrupo == 's');

    cout << "Programa finalizado." << endl;
    return 0;
}
