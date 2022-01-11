#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[2] <= 290.81100000000004) {
		if (features[346] <= 23.50555) {
			if (features[258] <= 333.041) {
				if (features[5] <= 25.9583) {
					if (features[0] <= 73.3401) {
						return ( "jazz");
					} else {
						return ( "classical");
					}
				} else {
					if (features[444] <= 4.868145) {
						return ( "classical");
					} else {
						if (features[0] <= 33.9271) {
							return ( "classical");
						} else {
							return ( "jazz");
						}
					}
				}
			} else {
				return ( "jazz");
			}
		} else {
			if (features[336] <= 91.1139) {
				if (features[256] <= 20.10535) {
					if (features[66] <= 15.3964) {
						return ( "reggae");
					} else {
						if (features[54] <= 44.79605) {
							return ( "country");
						} else {
							if (features[0] <= 11.556899999999999) {
								return ( "jazz");
							} else {
								if (features[0] <= 32.360699999999994) {
									return ( "disco");
								} else {
									if (features[0] <= 74.07499999999999) {
										return ( "classical");
									} else {
										return ( "rock");
									}
								}
							}
						}
					}
				} else {
					if (features[1] <= 61.876999999999995) {
						return ( "classical");
					} else {
						return ( "jazz");
					}
				}
			} else {
				if (features[14] <= 205.6225) {
					if (features[0] <= 149.71015) {
						return ( "rock");
					} else {
						return ( "reggae");
					}
				} else {
					return ( "blues");
				}
			}
		}
	} else {
		if (features[246] <= 49.17305) {
			if (features[151] <= 24.46415) {
				if (features[258] <= 660.025) {
					if (features[4] <= 231.952) {
						if (features[21] <= 202.2265) {
							if (features[2] <= 298.3445) {
								return ( "hiphop");
							} else {
								return ( "jazz");
							}
						} else {
							if (features[0] <= 191.01475) {
								return ( "classical");
							} else {
								return ( "pop");
							}
						}
					} else {
						if (features[1] <= 305.9125) {
							if (features[412] <= 16.81625) {
								if (features[0] <= 47.2997) {
									if (features[257] <= 213.17) {
										if (features[4] <= 1023.3219999999999) {
											return ( "country");
										} else {
											return ( "rock");
										}
									} else {
										if (features[0] <= 34.680099999999996) {
											return ( "blues");
										} else {
											return ( "jazz");
										}
									}
								} else {
									if (features[291] <= 230.26999999999998) {
										if (features[2] <= 611.992) {
											if (features[34] <= 89.6548) {
												return ( "jazz");
											} else {
												return ( "disco");
											}
										} else {
											if (features[0] <= 149.4018) {
												return ( "classical");
											} else {
												return ( "blues");
											}
										}
									} else {
										return ( "blues");
									}
								}
							} else {
								if (features[1] <= 146.92000000000002) {
									return ( "blues");
								} else {
									if (features[7] <= 239.728) {
										if (features[0] <= 64.8746) {
											if (features[0] <= 51.4752) {
												return ( "disco");
											} else {
												return ( "classical");
											}
										} else {
											return ( "metal");
										}
									} else {
										return ( "rock");
									}
								}
							}
						} else {
							if (features[2] <= 390.5915) {
								return ( "blues");
							} else {
								if (features[274] <= 206.274) {
									if (features[340] <= 40.49225) {
										if (features[201] <= 8.43009) {
											return ( "rock");
										} else {
											if (features[0] <= 136.9657) {
												return ( "metal");
											} else {
												return ( "pop");
											}
										}
									} else {
										if (features[2] <= 646.819) {
											return ( "country");
										} else {
											if (features[0] <= 136.591) {
												return ( "jazz");
											} else {
												return ( "reggae");
											}
										}
									}
								} else {
									if (features[425] <= 39.39265) {
										if (features[142] <= 38.039500000000004) {
											if (features[2] <= 441.336) {
												return ( "reggae");
											} else {
												if (features[259] <= 673.3040000000001) {
													return ( "country");
												} else {
													return ( "classical");
												}
											}
										} else {
											if (features[0] <= 124.5983) {
												return ( "jazz");
											} else {
												return ( "pop");
											}
										}
									} else {
										return ( "rock");
									}
								}
							}
						}
					}
				} else {
					if (features[5] <= 536.688) {
						if (features[485] <= 0.764227) {
							if (features[333] <= 40.277249999999995) {
								return ( "blues");
							} else {
								if (features[0] <= 235.53199999999998) {
									if (features[2] <= 926.9255) {
										if (features[0] <= 147.18099999999998) {
											return ( "disco");
										} else {
											return ( "country");
										}
									} else {
										return ( "jazz");
									}
								} else {
									return ( "hiphop");
								}
							}
						} else {
							if (features[122] <= 27.4954) {
								if (features[257] <= 554.3589999999999) {
									if (features[8] <= 396.8625) {
										if (features[6] <= 425.4435) {
											if (features[0] <= 99.42155) {
												return ( "jazz");
											} else {
												if (features[0] <= 135.774) {
													return ( "blues");
												} else {
													return ( "disco");
												}
											}
										} else {
											return ( "country");
										}
									} else {
										return ( "reggae");
									}
								} else {
									if (features[8] <= 377.78700000000003) {
										return ( "reggae");
									} else {
										return ( "country");
									}
								}
							} else {
								if (features[0] <= 228.35) {
									if (features[0] <= 96.2075) {
										return ( "disco");
									} else {
										if (features[0] <= 131.29399999999998) {
											return ( "rock");
										} else {
											return ( "reggae");
										}
									}
								} else {
									return ( "hiphop");
								}
							}
						}
					} else {
						if (features[476] <= 3.09567) {
							if (features[313] <= 145.10399999999998) {
								if (features[0] <= 129.16899999999998) {
									if (features[0] <= 75.4944) {
										return ( "reggae");
									} else {
										return ( "rock");
									}
								} else {
									return ( "blues");
								}
							} else {
								if (features[0] <= 451.43399999999997) {
									return ( "country");
								} else {
									if (features[0] <= 916.9804999999999) {
										return ( "metal");
									} else {
										return ( "reggae");
									}
								}
							}
						} else {
							if (features[259] <= 648.2655) {
								if (features[4] <= 624.1855) {
									if (features[0] <= 203.9735) {
										return ( "pop");
									} else {
										return ( "classical");
									}
								} else {
									return ( "country");
								}
							} else {
								if (features[375] <= 29.76545) {
									if (features[44] <= 91.58789999999999) {
										if (features[8] <= 353.2305) {
											return ( "pop");
										} else {
											if (features[8] <= 580.7295) {
												return ( "reggae");
											} else {
												if (features[0] <= 161.0725) {
													return ( "classical");
												} else {
													return ( "disco");
												}
											}
										}
									} else {
										return ( "jazz");
									}
								} else {
									if (features[2] <= 1966.055) {
										return ( "rock");
									} else {
										return ( "hiphop");
									}
								}
							}
						}
					}
				}
			} else {
				if (features[242] <= 10.02538) {
					if (features[80] <= 94.3139) {
						if (features[262] <= 682.7155) {
							if (features[1] <= 1199.335) {
								if (features[62] <= 91.74265) {
									if (features[258] <= 661.809) {
										if (features[10] <= 181.825) {
											if (features[0] <= 170.6019) {
												return ( "metal");
											} else {
												return ( "blues");
											}
										} else {
											return ( "rock");
										}
									} else {
										if (features[5] <= 686.6485) {
											return ( "disco");
										} else {
											if (features[0] <= 247.2985) {
												return ( "country");
											} else {
												if (features[0] <= 299.7735) {
													return ( "reggae");
												} else {
													return ( "disco");
												}
											}
										}
									}
								} else {
									if (features[272] <= 189.81349999999998) {
										if (features[33] <= 132.3225) {
											return ( "metal");
										} else {
											if (features[0] <= 165.64785) {
												return ( "rock");
											} else {
												if (features[0] <= 287.1115) {
													return ( "hiphop");
												} else {
													return ( "disco");
												}
											}
										}
									} else {
										if (features[35] <= 92.22569999999999) {
											return ( "blues");
										} else {
											if (features[204] <= 15.709) {
												if (features[316] <= 174.3705) {
													return ( "rock");
												} else {
													return ( "disco");
												}
											} else {
												if (features[7] <= 588.5285) {
													return ( "hiphop");
												} else {
													return ( "country");
												}
											}
										}
									}
								}
							} else {
								if (features[5] <= 557.544) {
									return ( "hiphop");
								} else {
									if (features[1] <= 2012.99) {
										return ( "metal");
									} else {
										return ( "reggae");
									}
								}
							}
						} else {
							if (features[6] <= 799.759) {
								if (features[0] <= 105.37004999999999) {
									return ( "blues");
								} else {
									return ( "hiphop");
								}
							} else {
								return ( "blues");
							}
						}
					} else {
						if (features[289] <= 259.68600000000004) {
							if (features[257] <= 1889.6) {
								if (features[57] <= 86.1719) {
									return ( "blues");
								} else {
									if (features[256] <= 84.0844) {
										if (features[0] <= 84.4696) {
											return ( "rock");
										} else {
											return ( "reggae");
										}
									} else {
										if (features[274] <= 377.849) {
											if (features[8] <= 944.2909999999999) {
												if (features[21] <= 420.13) {
													return ( "metal");
												} else {
													return ( "rock");
												}
											} else {
												return ( "country");
											}
										} else {
											if (features[138] <= 78.501) {
												if (features[28] <= 225.0555) {
													return ( "rock");
												} else {
													return ( "hiphop");
												}
											} else {
												return ( "metal");
											}
										}
									}
								}
							} else {
								if (features[0] <= 1161.37) {
									return ( "hiphop");
								} else {
									return ( "disco");
								}
							}
						} else {
							if (features[214] <= 11.024999999999999) {
								if (features[15] <= 282.96500000000003) {
									if (features[0] <= 334.659) {
										return ( "rock");
									} else {
										return ( "metal");
									}
								} else {
									if (features[5] <= 1211.6) {
										return ( "blues");
									} else {
										return ( "country");
									}
								}
							} else {
								if (features[23] <= 309.225) {
									return ( "hiphop");
								} else {
									if (features[0] <= 441.672) {
										return ( "disco");
									} else {
										return ( "metal");
									}
								}
							}
						}
					}
				} else {
					if (features[36] <= 153.1245) {
						if (features[260] <= 613.6025) {
							if (features[7] <= 659.3445) {
								if (features[321] <= 110.399) {
									if (features[203] <= 20.29805) {
										return ( "jazz");
									} else {
										if (features[0] <= 229.28449999999998) {
											return ( "country");
										} else {
											if (features[3] <= 722.3064999999999) {
												return ( "hiphop");
											} else {
												if (features[0] <= 668.422) {
													return ( "rock");
												} else {
													return ( "reggae");
												}
											}
										}
									}
								} else {
									if (features[0] <= 179.1985) {
										return ( "pop");
									} else {
										return ( "reggae");
									}
								}
							} else {
								return ( "pop");
							}
						} else {
							if (features[295] <= 100.26365) {
								if (features[0] <= 288.76) {
									if (features[0] <= 156.69850000000002) {
										return ( "country");
									} else {
										return ( "disco");
									}
								} else {
									return ( "reggae");
								}
							} else {
								if (features[32] <= 181.023) {
									if (features[261] <= 495.922) {
										return ( "disco");
									} else {
										if (features[377] <= 39.70795) {
											return ( "pop");
										} else {
											if (features[9] <= 628.797) {
												return ( "hiphop");
											} else {
												return ( "rock");
											}
										}
									}
								} else {
									if (features[0] <= 677.2385) {
										return ( "reggae");
									} else {
										return ( "pop");
									}
								}
							}
						}
					} else {
						if (features[2] <= 2255.005) {
							if (features[422] <= 37.21065) {
								if (features[261] <= 467.03099999999995) {
									if (features[5] <= 405.988) {
										return ( "disco");
									} else {
										if (features[4] <= 496.18050000000005) {
											if (features[0] <= 188.769) {
												return ( "country");
											} else {
												return ( "reggae");
											}
										} else {
											return ( "jazz");
										}
									}
								} else {
									return ( "rock");
								}
							} else {
								if (features[11] <= 408.2815) {
									if (features[8] <= 691.069) {
										return ( "disco");
									} else {
										return ( "pop");
									}
								} else {
									if (features[128] <= 73.42595) {
										if (features[8] <= 562.88) {
											if (features[2] <= 1790.145) {
												return ( "disco");
											} else {
												return ( "hiphop");
											}
										} else {
											return ( "pop");
										}
									} else {
										return ( "rock");
									}
								}
							}
						} else {
							if (features[69] <= 181.3955) {
								if (features[3] <= 1842.65) {
									return ( "hiphop");
								} else {
									if (features[0] <= 646.553) {
										return ( "jazz");
									} else {
										if (features[0] <= 1073.2355) {
											return ( "reggae");
										} else {
											return ( "pop");
										}
									}
								}
							} else {
								return ( "country");
							}
						}
					}
				}
			}
		} else {
			if (features[256] <= 297.83500000000004) {
				if (features[2] <= 952.719) {
					return ( "reggae");
				} else {
					return ( "disco");
				}
			} else {
				if (features[3] <= 1859.12) {
					if (features[10] <= 775.8824999999999) {
						if (features[36] <= 515.171) {
							return ( "pop");
						} else {
							return ( "rock");
						}
					} else {
						return ( "hiphop");
					}
				} else {
					if (features[1] <= 2228.325) {
						return ( "pop");
					} else {
						return ( "hiphop");
					}
				}
			}
		}
	}
}