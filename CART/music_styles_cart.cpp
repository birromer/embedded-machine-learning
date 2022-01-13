#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[383] <= 5.65756) {
		if (features[2] <= 250.031) {
			if (features[347] <= 29.6576) {
				if (features[5] <= 25.9583) {
					return ( "jazz");
				} else {
					if (features[257] <= 188.2185) {
						return ( "classical");
					} else {
						if (features[0] <= 58.05555) {
							return ( "jazz");
						} else {
							return ( "classical");
						}
					}
				}
			} else {
				return ( "jazz");
			}
		} else {
			if (features[280] <= 140.4115) {
				return ( "jazz");
			} else {
				if (features[1] <= 154.4885) {
					return ( "classical");
				} else {
					if (features[0] <= 80.4121) {
						return ( "country");
					} else {
						return ( "blues");
					}
				}
			}
		}
	} else {
		if (features[253] <= 49.6104) {
			if (features[169] <= 25.82315) {
				if (features[477] <= 1.080255) {
					if (features[337] <= 75.2278) {
						if (features[322] <= 24.518700000000003) {
							if (features[12] <= 137.0505) {
								return ( "blues");
							} else {
								if (features[0] <= 52.7727) {
									return ( "classical");
								} else {
									return ( "country");
								}
							}
						} else {
							if (features[462] <= 3.549855) {
								if (features[0] <= 17.0328) {
									return ( "disco");
								} else {
									return ( "jazz");
								}
							} else {
								if (features[0] <= 94.22515) {
									return ( "rock");
								} else {
									return ( "country");
								}
							}
						}
					} else {
						if (features[3] <= 864.4114999999999) {
							return ( "blues");
						} else {
							return ( "jazz");
						}
					}
				} else {
					if (features[9] <= 269.8295) {
						if (features[2] <= 709.1275) {
							if (features[234] <= 0.6343099999999999) {
								if (features[269] <= 131.599) {
									return ( "metal");
								} else {
									return ( "rock");
								}
							} else {
								if (features[266] <= 244.085) {
									return ( "country");
								} else {
									return ( "jazz");
								}
							}
						} else {
							if (features[1] <= 1322.27) {
								if (features[176] <= 21.12545) {
									return ( "reggae");
								} else {
									return ( "disco");
								}
							} else {
								if (features[7] <= 282.6685) {
									return ( "hiphop");
								} else {
									return ( "reggae");
								}
							}
						}
					} else {
						if (features[489] <= 0.9557535) {
							if (features[10] <= 415.051) {
								if (features[233] <= 0.8179605) {
									return ( "blues");
								} else {
									return ( "blues");
								}
							} else {
								if (features[3] <= 995.065) {
									return ( "country");
								} else {
									return ( "blues");
								}
							}
						} else {
							if (features[0] <= 126.712) {
								if (features[287] <= 273.58349999999996) {
									return ( "country");
								} else {
									return ( "classical");
								}
							} else {
								if (features[465] <= 11.762699999999999) {
									return ( "jazz");
								} else {
									return ( "rock");
								}
							}
						}
					}
				}
			} else {
				if (features[258] <= 2000.21) {
					if (features[92] <= 94.00815) {
						if (features[27] <= 156.635) {
							if (features[258] <= 814.8154999999999) {
								if (features[8] <= 272.923) {
									return ( "metal");
								} else {
									return ( "blues");
								}
							} else {
								if (features[9] <= 208.995) {
									return ( "hiphop");
								} else {
									return ( "reggae");
								}
							}
						} else {
							if (features[262] <= 394.3815) {
								if (features[258] <= 651.623) {
									return ( "rock");
								} else {
									return ( "disco");
								}
							} else {
								if (features[195] <= 31.800850000000004) {
									return ( "blues");
								} else {
									return ( "disco");
								}
							}
						}
					} else {
						if (features[219] <= 19.324199999999998) {
							if (features[293] <= 311.5825) {
								if (features[257] <= 291.389) {
									return ( "rock");
								} else {
									return ( "metal");
								}
							} else {
								if (features[99] <= 76.32475) {
									return ( "rock");
								} else {
									return ( "blues");
								}
							}
						} else {
							if (features[329] <= 156.264) {
								if (features[260] <= 639.107) {
									return ( "country");
								} else {
									return ( "hiphop");
								}
							} else {
								if (features[1] <= 566.657) {
									return ( "rock");
								} else {
									return ( "disco");
								}
							}
						}
					}
				} else {
					if (features[260] <= 632.8175000000001) {
						return ( "reggae");
					} else {
						if (features[24] <= 191.1805) {
							if (features[26] <= 217.22) {
								return ( "hiphop");
							} else {
								return ( "pop");
							}
						} else {
							if (features[309] <= 217.553) {
								if (features[9] <= 379.4435) {
									return ( "disco");
								} else {
									return ( "pop");
								}
							} else {
								if (features[24] <= 376.428) {
									return ( "hiphop");
								} else {
									return ( "rock");
								}
							}
						}
					}
				}
			}
		} else {
			if (features[0] <= 244.131) {
				return ( "disco");
			} else {
				if (features[47] <= 69.28435) {
					return ( "reggae");
				} else {
					if (features[60] <= 284.66700000000003) {
						if (features[2] <= 4057.255) {
							if (features[10] <= 775.8824999999999) {
								return ( "pop");
							} else {
								return ( "hiphop");
							}
						} else {
							return ( "hiphop");
						}
					} else {
						if (features[0] <= 460.774) {
							return ( "rock");
						} else {
							return ( "reggae");
						}
					}
				}
			}
		}
	}
}