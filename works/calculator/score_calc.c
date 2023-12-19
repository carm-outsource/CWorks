#include <stdio.h>
#include <math.h>
#include <stdbool.h>

static bool closer(const double avg, const double a, const double b) {
    return fabs(avg - a) < fabs(avg - b);
}

int main() {
    double scores[10];
    printf("Please input the scores (1-100): \n");
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &scores[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score: %.2lf\n", scores[i]);
            return 1;
        }
    }

    double min = -1, max = -1, total = 0;
    for (int i = 0; i < 10; i++) {
        total += scores[i];
        if (min == -1 || scores[i] < min) min = scores[i];
        if (max == -1 || scores[i] > max) max = scores[i];
    }
    double avg = (total - min - max) / 8;
    printf("Max score is %.2lf, skipped.\n", max);
    printf("Min score is %.2lf, skipped.\n", min);
    printf("Average score is %.2lf\n", avg);

    double closest = -1, farthest = -1;
    for (int i = 0; i < 10; i++) {
        if (scores[i] == min || scores[i] == max) continue;
        if (closest == -1 || closer(avg, scores[i], closest)) {
            closest = scores[i];
        }
        if (farthest == -1 || !closer(avg, scores[i], farthest)) {
            farthest = scores[i];
        }
    }
    printf("Closest score is %.2lf\n", closest);
    printf("Farthest score is %.2lf\n", farthest);

    return 0;
}
