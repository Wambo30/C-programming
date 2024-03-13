#include "projekt8.h" 


Bruch betrag(Bruch const& x)
{
	if (x < 0)
		return -x;
	return x;
}
	
Bruch* loeseLGS(Bruch* matrix[] , Bruch rechteSeite[])
{
	
	//dim == größe von matrix
	
	//pivotisierung
	for (size_t i = 0; i < Dim; ++i)
	{
		size_t p = i;
		for (size_t k = i+1; k< Dim; ++k)
		{
			if ( betrag(matrix[p][i]) < betrag(matrix[k][i]) )
				p = k;

		}
	//vertausche zeile ap mit ai sowieo bp mit bi
		if (p != i)
		{
			Bruch* temp = matrix[p];	//temp == zwischenvariable
			matrix[p] = matrix[i];
			matrix[i] = temp;

			Bruch temp1 = rechteSeite[p];
			rechteSeite[p] = rechteSeite[i];
			rechteSeite[i] = temp1;
		}

		if (matrix[i][i] == 0)
			return nullptr;	//keine lösung


		//vorwärtselimination

		for (size_t k = i + 1; k < Dim; ++k)
		{
			Bruch s = matrix[k][i] / matrix[i][i];
			for (size_t j = i + 1; j < Dim; ++j)
				matrix[k][j] = matrix[k][j] - s * matrix[i][j];
			rechteSeite[k] = rechteSeite[k] - s * rechteSeite[i];
		}
		
	}

	//rückwärtseinsetzen

	for (size_t i = Dim - 1; i < Dim ; i--)
	{
		for (size_t k = i + 1; k < Dim; k++)
			rechteSeite[i] = rechteSeite[i] - matrix[i][k] * rechteSeite[k];
		rechteSeite[i] = rechteSeite[i] / matrix[i][i];
	}
	return rechteSeite;	//ausgabe lösung


}
