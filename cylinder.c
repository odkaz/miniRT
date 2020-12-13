/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:51:11 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 10:54:57 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		get_t_cy(t_cylinder cy, t_vector ray, t_vector cnt)
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		t;

	a = inner(cross(ray, cy.norm), cross(ray, cy.norm));
	b = 2 * inner(cross(vector_sub(cnt, cy.pos), cy.norm), cross(ray, cy.norm));
	c = inner(cross(vector_sub(cnt, cy.pos), cy.norm), \
	cross(vector_sub(cnt, cy.pos), cy.norm)) - pow(cy.r, 2);
	d = b * b - 4.0 * a * c;
	if (d < 0)
		return (0);
	t = (-b - sqrt(d)) / (2 * a);
	return (t);
}

t_vector	get_normal_cy(t_cylinder cy, t_vector p)
{
	t_vector	cp;
	t_vector	cq;
	t_vector	q;

	cp = vector_sub(p, cy.pos);
	cq = vector_mlt(cy.norm, inner(cy.norm, cp));
	q = vector_add(cy.pos, cq);
	return (vector_sub(p, q));
}

double		large_t_cy(t_cylinder cy, t_vector ray, t_vector cnt)
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		t;

	a = inner(cross(ray, cy.norm), cross(ray, cy.norm));
	b = 2 * inner(cross(vector_sub(cnt, cy.pos), cy.norm), cross(ray, cy.norm));
	c = inner(cross(vector_sub(cnt, cy.pos), cy.norm), \
	cross(vector_sub(cnt, cy.pos), cy.norm)) - pow(cy.r, 2);
	d = b * b - 4.0 * a * c;
	if (d < 0)
		return (0);
	t = (-b + sqrt(d)) / (2 * a);
	return (t);
}
