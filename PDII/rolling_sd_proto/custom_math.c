double standard_deviation(double* data, int num_values)
{
    double sum = 0;
    double avg = mean(data, num_values);
    //subtract each value from mean, then square
    for(int i = 0; i < num_values; ++i)
    {
        sum += pow(data[i] - avg, 2);
    }
    return sqrt(sum/num_values);
}

double mean(double* data, int num_values)
{
    double avg = 0;
    for(int i = 0; i < num_values; ++i)
    {
        avg += data[i];
    }
    avg  = avg / num_values;
    return avg;
}